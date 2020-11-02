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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mod = pow(10,9) + 7;
    int n,x;
    cin >> n >> x;
    vector<int> arr = readArray<int>(n);

    vector<int> dp(x+1, 0);
    for (int j = 0; j < n; ++j) {
        if (arr[j] <= x) {
            dp[arr[j]]++;
        }
    }
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i-arr[j] >= 0) {
                dp[i] = (dp[i] + dp[i-arr[j]]) % mod;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}