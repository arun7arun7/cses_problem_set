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
vector<unordered_set<int>> graph;
vector<int> degree;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> m;
	graph.assign(n, unordered_set<int>());
	degree.assign(n,0);
	
	for (int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		--a;--b;
		graph[a].insert(b);
		graph[b].insert(a);
		degree[a]++;degree[b]++;
	}
	
	for (int i = 0;i < n; i++) {
		if (degree[i] & 1) {
			cout << "IMPOSSIBLE" << "\n";
			return 0;
		}
	}
	
	stack<int> st;
	vector<int> res,temp;
	st.push(0);
	while(!st.empty()) {
		int v = st.top();
		if (degree[v] == 0) {
			res.push_back(v+1);
			st.pop();
		}
		else {
			int neighbor = *graph[v].begin();
			graph[v].erase(neighbor);
			graph[neighbor].erase(v);
			degree[v]--;degree[neighbor]--;
			st.push(neighbor);
		}
	}
	
	if (res.size() == m+1) {
		printArray(res, ' ');
	}
	else {
		cout << "IMPOSSIBLE" << "\n";
	}
    return 0;
}
