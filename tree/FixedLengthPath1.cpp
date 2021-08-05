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

int n, k;
vector<vector<int>> neighbors;
vector<int> subtree_size, parent;
vector<bool> blocked;

void dfs2(int cur, int p, int dep, vector<int>& depth_sum) {
    depth_sum[dep] += 1;
    for (int neighbor : neighbors[cur]) {
        if (neighbor != p && !blocked[neighbor]) {
            dfs2(neighbor, cur, dep+1, depth_sum);
        }
    }
}

void dfs3(int cur, int p, int dep, vector<int>& depth_sum, ll& val, int& comp_size) {
    if (k-dep >= 0 && k-dep <= comp_size) {
        val += depth_sum[k-dep];
    }
    for (int neighbor : neighbors[cur]) {
        if (neighbor != p && !blocked[neighbor]) {
            dfs3(neighbor, cur, dep+1, depth_sum, val, comp_size);
        }
    }
}

ll solve_tree(int root, int comp_size) {
    vector<int> depth_sum(comp_size+1, 0);

    ll res = 0;
    for (int neighbor : neighbors[root]) {
        if (!blocked[neighbor]) {
            /*
            queue<pair<int,int>> q;
            q.push({neighbor, 1});
            ll val = 0;
            while (q.size() > 0) {
                int cur_node = q.front().first, cur_depth = q.front().second;
                if (k-cur_depth >= 0 && k-cur_depth <= comp_size) {
                    val += depth_sum[k - cur_depth];   
                }
                q.pop();
                for (int neighbor2 : neighbors[cur_node]) {
                    if (neighbor2 != cur_node && !blocked[neighbor2]) {
                        q.push({neighbor2, cur_depth+1});
                    }
                }
            }
            res += val;
            */
            ll val = 0;
            dfs3(neighbor, neighbor, 1, depth_sum, val, comp_size);
            res += val;
            dfs2(neighbor, neighbor, 1, depth_sum);            
        }
    }
    if (comp_size >= k) {
        res += depth_sum[k];
    }
    return res;
}

void dfs(int cur, int p) {
    subtree_size[cur] = 1;
    parent[cur] = p;
    for (int neighbor : neighbors[cur]) {
        if (neighbor != p && !blocked[neighbor]) {
            dfs(neighbor, cur);
            subtree_size[cur] += subtree_size[neighbor];
        }
    }
}

ll go(int entry_point) {
    dfs(entry_point, entry_point);

    queue<int> q;
    q.push(entry_point);
    int centroid = entry_point, best_size = subtree_size[entry_point];
    while (q.size() > 0) {
        int cur = q.front(), max_size = 0;
        q.pop();
        for (int neighbor : neighbors[cur]) {
            if (neighbor != parent[cur] && !blocked[neighbor]) {
                q.push(neighbor);
                max_size = max(max_size, subtree_size[neighbor]);
            }
        }
        max_size = max(max_size, subtree_size[entry_point] - subtree_size[cur]);
        if (max_size < best_size) {
            best_size = max_size;
            centroid = cur;
        }
    }

    debug(centroid+1);
    blocked[centroid] = true;
    ll res = solve_tree(centroid, subtree_size[entry_point]);
    debug(centroid+1, res);

    for (int neighbor : neighbors[centroid]) {
        if (!blocked[neighbor]) {
            res += go(neighbor);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    neighbors.assign(n, vector<int>());
    subtree_size.resize(n);
    parent.resize(n);
    blocked.assign(n, false);
    for (int i = 1; i < n; i++) {
        int a,b;
        cin >> a >> b;
        --a;--b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    ll res = go(0);
    cout << res << "\n";
    return 0;
}
