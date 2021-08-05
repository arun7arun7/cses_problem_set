#include <bits/stdc++.h>


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
vector<int> indegree,outdegree;
vector<bool> visited;

void dfs(int cur) {
	visited[cur] = true;
	for (int neighbor : graph[cur]) {
		if (!visited[cur]) {
			dfs(neighbor);
		}
	}
}

vector<int> euler_circuit(int start) {
	vector<int> res;
	stack<int> st;
	st.push(start);
	while (!st.empty()) {
		int v = st.top();
		if (outdegree[v] == 0) {
			res.push_back(v);
			st.pop();
		}
		else {
			int neighbor = *graph[v].begin();
			graph[v].erase(neighbor);
			outdegree[v]--;indegree[neighbor]--;
			st.push(neighbor);
		}
	}
	reverse(res.begin(), res.end());
	return res;
}

#define ONLINE_JUDGE
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> m;
	graph.assign(n, unordered_set<int>());
	indegree.assign(n,0);
	outdegree.assign(n,0);
	visited.assign(n, false);
	
	for (int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		--a;--b;
		graph[a].insert(b);
		outdegree[a]++;indegree[b]++;
	}
	
	// dfs(0);
	int in = -1, out = -1;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		// if (visited[i]) 
			if (indegree[i] == outdegree[i]) {
				continue;
			}
			if (indegree[i] - outdegree[i] == 1) {
				if (in == -1) {
					in = i;
				}
				else {
					ok = false;
					break;
				}
			}
			else if (outdegree[i] - indegree[i] == 1) {
				if (out == -1) {
					out = i;
				}
				else {
					ok = false;
					break;
				}
			}
			else {
				ok = false;
				break;
			}
		// }
	}
	debug(in+1,out+1,ok+1);
	if (!ok) {
		cout << "IMPOSSIBLE" << "\n";
		return 0;
	}
	
	vector<int> res;
	if (in == -1 && out == -1) {
		if (graph[n-1].find(0) == graph[n-1].end()) {
			cout << "IMPOSSIBLE" << "\n";
			return 0;
		}
		vector<int> ec = euler_circuit(0);
		// turn ec starting with 1 and ending with n
		int sz = ec.size()-1;
		int k = sz-1;
		for (int i = 0; i < sz-1; i++) {
			if (ec[i] == n-1 && ec[i+1] == 0) {
				k = i;
				break;
			}
		}
		int itr = k + 1;
		while (itr < sz) {
			res.push_back(ec[itr++]);
		}
		itr = 0;
		while (itr <= k) {
			res.push_back(ec[itr++]);
		}
	}
	else if (in == -1 && out != -1) {
		if (out == 0 && graph[out].find(n-1) != graph[out].end()) {
			graph[out].erase(n-1);
			outdegree[out]--;indegree[n-1]--;
			vector<int> ec = euler_circuit(n-1);
			// out + ec ending with n
			res.push_back(out);
			for (int i = 0; i < ec.size(); i++) {
				res.push_back(ec[i]);
			}
		}
		else {
			cout << "IMPOSSIBLE" << "\n";
			return 0;
		}
	}
	else if (in != -1 && out == -1) {
		if (in == n-1 && graph[0].find(n-1) != graph[0].end()) {
			graph[0].erase(in);
			outdegree[0]--;indegree[in]--;
			vector<int> ec = euler_circuit(0);
			// ec + n
			for (int i = 0; i < ec.size(); i++) {
				res.push_back(ec[i]);
			}
			res.push_back(n-1);
		}
		else {
			cout << "IMPOSSIBLE" << "\n";
			return 0;
		}
	}
	else {
		if (out == 0 && in == n-1) {
			graph[in].insert(out);
			outdegree[in]++;indegree[out]++;
			vector<int> ec = euler_circuit(0);
			// turn ec starting with 1 and ending with n
			debug(ec);
			int sz = ec.size()-1;
			int k = sz-1;
			for (int i = 0; i < sz-1; i++) {
				if (ec[i] == n-1 && ec[i+1] == 0) {
					k = i;
					break;
				}
			}
			int itr = k + 1;
			while (itr < sz) {
				res.push_back(ec[itr++]);
			}
			itr = 0;
			while (itr <= k) {
				res.push_back(ec[itr++]);
			}
		}
		else {
			cout << "IMPOSSIBLE" << "\n";
			return 0;
		}
	}
	
	if (res.size() == m+1) {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] + 1 << ' ';
		}
	}
	else {
		cout << "IMPOSSIBLE" << "\n";
		return 0;
	}
    return 0;
}
