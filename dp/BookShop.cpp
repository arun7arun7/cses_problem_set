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

int fun(int i, int x, vector<vector<int>>& dp, vector<int>& price, vector<int>& pages, int &n) {
    if (i == n) {
        return 0;
    }
    if (dp[i][x] != -1) {
        return dp[i][x];
    }
    dp[i][x] = fun(i+1, x, dp,price,pages,n);
    if (price[i] <= x) {
        dp[i][x] = max(dp[i][x], pages[i] + fun(i+1, x-price[i], dp,price,pages,n));
    }
    return dp[i][x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin >> n >> x;

    vector<int> price = readArray<int>(n);
    vector<int> pages = readArray<int>(n);

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-price[i-1];
            if (left >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
            }
        }
    }
    // cout << fun(0, x, dp, price, pages, n);
    cout << dp[n][x];
    return 0;
}