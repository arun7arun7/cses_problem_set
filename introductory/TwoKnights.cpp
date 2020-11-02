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

    int n;
    cin >> n;

    vector<ll> ans(n);
    ans[0] = 0;
    if (n >= 2)
        ans[1] = 6;
    if (n >= 3) {
        ans[2] = 28;
    }
    for (int i = 4; i <= n; i++) {
        ll possible = 0;
        possible += ((i - 4) * (i - 4) * 8) + 48 + (4 * ((i - 4) * 4 + (i - 4) * 6));
        possible /= 2;

        ll cells = (ll)i*i;
        ll total = (cells*(cells-1)) / 2;
        ans[i-1] = (total - possible);
    }
    printArray<ll>(ans, '\n');
    return 0;
}