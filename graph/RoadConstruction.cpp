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
	
	int size_of_component(int v) {
		return size[find_sets(v)];
	}
	
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m;
	cin >> n >> m;
	Dsu dsu(n);
	int connected_components = n, largest_size = 1;
	for (int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		--a;--b;
		if (dsu.find_sets(a) != dsu.find_sets(b)) {
			connected_components--;
			dsu.union_sets(a, b);
			int sz = dsu.size_of_component(a);
			largest_size = max(largest_size, sz);
		}
		cout << connected_components << " " << largest_size << "\n";
	}
    return 0;
}
