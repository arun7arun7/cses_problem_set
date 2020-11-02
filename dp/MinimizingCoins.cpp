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
int inf = pow(10, 9);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin >> n >> x;
    vector<int> arr = readArray<int>(n);

    vector<int> dp(x+1, inf);
    dp[0] = 0;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i-arr[j] >= 0 && dp[i-arr[j]] != -1) {
                dp[i] = min(dp[i], 1+dp[i-arr[j]]);
            }
        }
        if (dp[i] == inf) {
            dp[i] = -1;
        }
    }
    cout << dp[x];
    return 0;
}