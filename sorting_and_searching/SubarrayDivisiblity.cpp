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

int modulo(ll a, int n) {
    return ((a%n + n) % n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr = readArray<int>(n);
    vector<ll> prefixSum(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        prefixSum[i] = sum;
    }
    vector<int> count(n, 0);
    ll ans = 0;
    for (ll element : prefixSum) {
        int mod = modulo(element, n);
        ans += count[mod];
        if (mod == 0) {
            ans++;
        }
        count[mod]++;
    }
    cout << ans;
    return 0;
}