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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin >> a >> b;

    int inf = 1e9;

    vector<vector<int>> dp(a+1, vector<int>(b+1, inf));
    dp[1][1] = 0;
    for (int i = 2; i <= b; ++i) {
        dp[1][i] = i-1;
    }
    for (int i = 2; i <= a; ++i) {
        dp[i][1] = i-1;
    }
    for (int i = 2; i <= a; ++i) {
        for (int j = 2; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            for (int k = 1; k < i; ++k) {
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
            }
            for (int k = 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
            }
        }
    }
    cout << dp[a][b];
    return 0;
}