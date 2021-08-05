#include <bits/stdc++.h>
// #define ONLINE_JUDGE

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

int n,m,sz;
vector<vector<int>> neighbors,st;
vector<int> parent, depth, add, sub,result;

void process() {
	sz = (int)log2(n) + 1;
	st.assign(n, vector<int>(sz, -1));
	for (int i = 0; i < n; i++) {
		st[i][0] = parent[i];
	}
	for (int j = 1; j < sz; j++) {
		for (int i = 0; i < n; i++) {
			if (st[i][j-1] != -1) {
				st[i][j] = st[st[i][j-1]][j-1];
			}
		}
	}
}

int kth_ancesstor(int x, int k) {
	int bit = 0;
	while (bit < sz && x != -1){
		if (k & (1 << bit)) {
			x = st[x][bit];
		}
		bit++;
	}
	return x;
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) {
		swap(a,b);
	}
	int dist = depth[a] - depth[b];
	a = kth_ancesstor(a, dist);
	if (a == b) {
		return a;
	}
	int bit = sz-1;
	while (bit >= 0) {
		if (st[a][bit] != st[b][bit]) {
			a = st[a][bit];
			b = st[b][bit];
		}
		bit--;
	}
	return parent[a];
}

void dfs(int cur, int par, int dep) {
	parent[cur] = par;
	depth[cur] = dep;
	for (int neighbor : neighbors[cur]) {
		if (neighbor != par) {
			dfs(neighbor, cur, dep+1);
		}
	}
}

void dfs2(int cur, int sum) {
	result[cur] = sum + add[cur];
	for (int neighbor : neighbors[cur]) {
		if (neighbor != parent[cur]) {
			dfs2(neighbor, result[cur] - sub[cur]);
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin >> n >> m;
	neighbors.assign(n, vector<int>());
	parent.reserve(n);
	depth.reserve(n);
	add.assign(n,0);
	sub.assign(n,0);
	result.reserve(n);
	for (int i = 0; i < n-1; i++) {
		int a,b;
		cin >> a >> b;
		--a;--b;
		neighbors[a].push_back(b);
		neighbors[b].push_back(a);
	}
	dfs(0,-1,0);
	process();
	for (int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		--a;--b;
		if (a == b) {
			add[a] += 1;
			continue;
		}
		int l = lca(a,b);
		debug(l);
		add[l] += 1;
		if (a != l) {
			sub[a] += 1;
		}
		if (b != l) {
			sub[b] += 1;
		}
	}
	debug(add, sub);
	dfs2(0,0);
	for (int i = 0; i < n; i++) {
		cout << result[i] << "\n";
	}
    return 0;
}
