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
vector<vector<int>> g, gt;
vector<bool> visited;
vector<int> order;

void dfs1(int v) {
	visited[v] = true;
	for (size_t i = 0; i < g[v].size(); i++) {
		if (!visited[g[v][i]]) {
			dfs1(g[v][i]);
		}
	}
	order.push_back(v);
}

void dfs2(int v) {
	visited[v] = true;
	for (size_t i = 0; i < gt[v].size(); i++) {
		if (!visited[gt[v][i]]) {
			dfs2(gt[v][i]);
		}
	}
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		
	cin >> n >> m;
	g.resize(n+1);
	gt.resize(n+1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		gt[b].push_back(a);
	}
	visited.assign(n+1, false);
	for (int v = 1; v <= n; v++) {
		if (!visited[v]) {
			dfs1(v);
		}
	}
	
	visited.assign(n+1, false);
	int v1 = order[n-1];
	dfs2(v1);
	int v2 = -1;
	for (int v = 1; v <= n; v++) {
		if (!visited[v]) {
			v2 = v;
			break;
		}
	}
	
	if (v2 == -1) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
		cout << v2 << " " << v1 << "\n";
	}
    return 0;
}
