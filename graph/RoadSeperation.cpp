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

struct Edge {
	int a, b, c;
};

class Dsu {
	int n;
	vector<int> parent, size;
public:
	Dsu(int n) {
		this->n = n;
		parent.resize(n);
		size.assign(n, 1);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	
	void union_sets(int a, int b) {
		a = find_sets(a);
		b = find_sets(b);
		if (a != b) {
			if (size[a] < size[b]) {
				swap(a, b);
			}
			parent[b] = a;
			size[a] += size[b];
		}
	}
	
	int find_sets(int v) {
		if (v == parent[v]) {
			return v;
		}
		return parent[v] = find_sets(parent[v]);
	}
};


bool compare(Edge& a, Edge& b) {
	return a.c < b.c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<Edge> edges(m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c; 
		edges[i] = {a ,b, c};
	}
	sort(edges.begin(), edges.end(), &compare);
	//debug(edges);
	ll res = 0;
	Dsu dsu(n);
	for (int i = 0; i < m; i++) {
		int s1 = dsu.find_sets(edges[i].a-1), s2 = dsu.find_sets(edges[i].b-1);
		if (s1 != s2) {
			dsu.union_sets(edges[i].a-1, edges[i].b-1);
			res += edges[i].c;
		}
	}
	int r = dsu.find_sets(0);
	bool disconnected = false;
	for (int i = 1; i < n; i++) {
		if (dsu.find_sets(i) != r) {
			disconnected = true;
			break;
		}
	}
	if (disconnected) {
		cout << "IMPOSSIBLE" << "\n";
	}
	else {
		cout << res << "\n";
	}
    return 0;
}
