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

    int inf = 1e9;
    int n;
    cin >> n;

    vector<int> dp(n+1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> digits;
        int j = i;
        while (j > 0) {
            digits.push_back(j%10);
            j /= 10;
        }

        for (int digit : digits) {
            dp[i] = min(dp[i], 1+dp[i-digit]);
        }
    }
    cout << dp[n];
    return 0;
}