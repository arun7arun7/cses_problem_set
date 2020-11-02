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
int n,mod;

ll fun(int i, int j, vector<string> &arr, vector<vector<int>>& dp) {
    if (i >= n || j >= n || arr[i][j] == '*') {
        return 0;
    }
    if (i == n-1 && j == n-1) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = (fun(i+1,j,arr,dp) + fun(i, j+1, arr, dp)) % mod;
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mod = 1e9 + 7;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n);
    for (int i = 0; i < n; ++i) {
        vector<int> vec(n);
        for (int j = 0; j < n; ++j) {
            vec[j] = -1;
        }
        dp[i] = vec;
    }
    cout << fun(0,0, arr, dp);
    return 0;
}