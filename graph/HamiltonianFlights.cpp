#include <bits/stdc++.h>
#define ONLINE_JUDGE

using namespace std;

typedef long long int ll;

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

int n,m;
vector<vector<int>> adj;
const int mod = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    adj.assign(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a][b] += 1;
        if (a == b) {
            debug(a);
        }
    }

    int k = n-1;
    vector<vector<ll>> dp(1 << k, vector<ll>(k, 0));
    dp[1][0] = 1;
    
    for (int i = 2; i < (1 << k); i++) {
        for (int u = 0; u < k; u++) {
            if ((i & (1 << u)) == 0) continue;
            for (int v = 0; v < k; v++) {
                if ((i & (1 << v)) == 0) continue;
                (dp[i][v] += (dp[i ^ (1 << v)][u] * adj[u][v])) %= mod;
            }
        }
        /*
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                (dp[i][j] *= (1 << adj[j][j])) %= mod;
            }
        }
        */
    }
    int mask = (1 << k) - 1;
    ll res = 0;
    for (int u = 0; u < k; u++) {
        (res += (dp[mask][u] * adj[u][n-1])) %= mod;
    }
    // (res *= (1 << adj[n-1][n-1])) %= mod;
    //debug(dp);
    cout << res << "\n";
    return 0;
}
