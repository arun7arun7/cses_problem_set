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
void printArray(vector<T> arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> a = readArray<int>(n);
    int prev = a[0];
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < prev) {
            ans += prev - a[i];
            continue;
        }
        prev = a[i];
    }
    cout << ans;
    return 0;
}
