#include <bits/stdc++.h>
#define ONLINE_JUDGE

using namespace std;

typedef long long ll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

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

int n,q,ti;
vector<vector<int>> neighbors;
vector<int> arr,in,out,flatten_tree, node_index_map;

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
        for (int v : bit) {
			debug(v);
		}
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        debug(r, ret);
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};



void dfs(int cur, int par) {
    in[cur] = ti;
    flatten_tree[ti] = arr[cur];
    node_index_map[cur] = ti;
    for (int neighbor : neighbors[cur]) {
        if (neighbor != par) {
            ti++;
            dfs(neighbor, cur);
        }
    }
    out[cur] = ti;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    neighbors.assign(n, vector<int>());
    in.resize(n);
    out.resize(n, 0);
    flatten_tree.resize(n, 0);
    arr.resize(n, 0);
    node_index_map.resize(n, 0);

    readArray(arr, n);
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        --a;--b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }
    debug(neighbors);
    ti = 0;
    dfs(0, -1);
    debug(arr);
    debug(in, out, flatten_tree, node_index_map);
    FenwickTree ft(flatten_tree);
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            int s,x;
            cin >> s >> x;
            --s;
            ft.add(node_index_map[s], x - arr[s]);
            arr[s] = x;
        }
        else
        {
            int s;
            cin >> s;
            --s;
            debug(s, in[s], out[s]);
            cout << ft.sum(in[s], out[s]) << "\n";
        }       
    }
    return 0;
}
