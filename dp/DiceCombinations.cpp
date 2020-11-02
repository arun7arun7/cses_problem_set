#include <bits/stdc++.h>

using namespace std;

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
int mod = pow(10,9)+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int j = 1;
        while ((i-j) >= 0 && j <= 6) {
            dp[i] = (dp[i] + dp[i-j]) % mod;
            j++;
        }
    }
    cout << dp[n];
    return 0;
}