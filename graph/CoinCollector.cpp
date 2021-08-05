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

int n,m,node;
vector<vector<int>> graph, transpose;
vector<unordered_set<int>> condensed_graph;
vector<int> cost, order, component;
vector<ll> condensed_topsort;
vector<bool> used;

void dfs1(int cur) {
	used[cur] = true;
	for (int neighbor : graph[cur]) {
		if (!used[neighbor]) {
			dfs1(neighbor);
		}
	}
	order.push_back(cur);
}

void dfs2(int cur, ll& sum) {
	component[cur] = node;
	sum += (ll)cost[cur];
	for (int neighbor : transpose[cur]) {
		if (component[neighbor] == -1) {
			dfs2(neighbor, sum);
		}
		else if (component[neighbor] != node) {
			condensed_graph[component[neighbor]].insert(node);
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> m;
	graph.assign(n, vector<int>());
	transpose.assign(n, vector<int>());
	cost.reserve(n);
	component.reserve(n);
	
	readArray(cost, n);
	for (int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		--a;--b;
		graph[a].push_back(b);
		transpose[b].push_back(a);
	}
	
	used.assign(n, false);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	debug(order);
	
	component.assign(n, -1);
	condensed_graph.assign(n, unordered_set<int>());
	node = 0;
	for (int i = 0; i < n; i++) {
		int v = order[n-1-i];
		if (component[v] == -1) {
			ll sum = 0;
			dfs2(v, sum);
			condensed_topsort.push_back(sum);
			node++;
		}
	}
	debug(component, condensed_graph, node);
	
	ll res = 0;
	vector<ll> dp(node, 0);
	for (int i = 0; i < node; i++) {
		dp[i] += condensed_topsort[i];
		res = max(res, dp[i]);
		for (int neighbor : condensed_graph[i]) {
			dp[neighbor] = max(dp[neighbor], dp[i]);
		}
	}
	debug(dp);
	
	cout << res << "\n";
    return 0;
}
