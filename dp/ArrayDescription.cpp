#include <bits/stdc++.h>

using namespace std;

void fastscan(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}

template <typename T>
vector<T> readArray(int s) {
    vector<T> arr(s);
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }
    return arr;
}

template <typename T>
void printArray(vector<T> arr, char delimitter) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << delimitter;
    }
    cout << endl;
}

typedef long long int ll;
int n,m,mod;
vector<int> arr;
vector<vector<int>> dp;

bool between(const int& num) {
    if (num >= 1 && num <= m) {
        return true;
    }
    return false;
}

bool between_and_abs(const int& num, const int& next) {
    if (num >= 1 && num <= m && abs(num-next) <= 1) {
        return true;
    }
    return false;
}

ll fun(int i, int prev) {
    if (i == n) {
        return 1;
    }

    if (dp[i][prev] != -1) {
        return dp[i][prev];
    }

    if (arr[i] != 0) {
        if (abs(arr[i] - prev) <= 1) {
            return 1;
        }
        return 0;
    }
    else {
        dp[i][prev] = 0;
        if (between(prev-1)) {
            (dp[i][prev] += fun(i+1, prev-1)) %= mod;
        }
        if (between(prev)) {
            (dp[i][prev] += fun(i+1, prev)) %= mod;
        }
        if (between(prev+1)) {
            (dp[i][prev] += fun(i+1, prev+1)) %= mod;
        }
    }
    return dp[i][prev];
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int n,m;
    mod = 1e9+7;
    cin >> n >> m;

    arr = readArray<int>(n);
    vector<int> nonzero;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            nonzero.push_back(i);
        }
    }
    dp.assign(n, vector<int>(m+1, -1));

    ll ans = 1;
    if (arr[0] == 0) {
        ll local = 0;
        for (int j = 1; j <= m; ++j) {
            (local += fun(1, j)) %= mod;
        }
        (ans *= local) %= mod;
    }
    for (int ind : nonzero) {
        (ans *= fun(ind+1, arr[ind])) %= mod;
    }
    cout << ans;
    return 0;
}