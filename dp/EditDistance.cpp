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

    string s1,s2;
    cin >> s1 >> s2;

    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1));

    dp[0][0] = 0;
    for (int i = 1; i <= n1; ++i) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n2; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            dp[i][j] = min(dp[i][j], min(1+dp[i][j-1], 1+dp[i-1][j]));
        }
    }
    cout << dp[n1][n2];
    return 0;
}