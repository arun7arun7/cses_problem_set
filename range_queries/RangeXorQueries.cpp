#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<T> readArray(vector<T>& arr, int s) {
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }
    return arr;
}

template <typename T>
void printArray(vector<T>& arr, char delimitter) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << delimitter;
    }
    cout << endl;
}

template<typename Map> typename Map::iterator
greatest_less(Map & m, typename Map::key_type const& k) {
    typename Map::iterator it = m.lower_bound(k);
    if(it != m.begin()) {
        return --it;
    }
    return m.end();
}

template<typename Map> typename Map::iterator
greatest_less_equality_consideration(Map & m, typename Map::key_type const& k) {
    typename Map::iterator it = m.upper_bound(k);
    if(it != m.begin()) {
        return --it;
    }
    return m.end();
}

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    readArray(a,n);

    vector<int> prefix_xor_sum(n+1);
    prefix_xor_sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix_xor_sum[i] = prefix_xor_sum[i-1] ^ a[i-1];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << (prefix_xor_sum[r] ^ prefix_xor_sum[l-1]) << "\n";
    }
    return 0;
}