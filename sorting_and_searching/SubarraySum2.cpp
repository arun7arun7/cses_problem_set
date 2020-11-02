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

    int n, x;
    cin >> n >> x;
    vector<int> arr = readArray<int>(n);
    vector<ll> prefixSum(n+1);
    prefixSum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i-1] + arr[i-1];
    }
    unordered_map<ll,int> count;
    count.reserve(n);
    count.max_load_factor(0.25);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (count.find(prefixSum[i]-x) != count.end()) {
            ans += count[prefixSum[i]-x];
        }
        if (prefixSum[i] == x) {
            ans++;
        }
        count[prefixSum[i]]++;
    }
    cout << ans;
    return 0;
}