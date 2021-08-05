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

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i,i,a[i]);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    void add(int l, int r, ll delta) {
        add(l, delta);
        add(r+1, -delta);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    readArray(arr, n);

    FenwickTree fenwickTree(arr);

    for (int i = 0; i < q; ++i) {
        int c;
        cin >> c;
        if (c == 1) {
            int a,b,u;
            cin >> a >> b >> u;
            fenwickTree.add(a-1, b-1 ,u);
        } else {
            int k;
            cin >> k;
            cout << fenwickTree.sum(k-1) << "\n";
        }
    }
    return 0;
}
