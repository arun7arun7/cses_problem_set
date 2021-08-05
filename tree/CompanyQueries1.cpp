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

int n,sz;
vector<vector<int>> st;
vector<int> parent;

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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int q;
	cin >> n >> q;
	parent.reserve(n);
	parent[0] = -1;
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		--p;
		parent[i] = p;
	}
	process();
	for (int i = 0; i < q; i++) {
		int x,k;
		cin >> x >> k;
		--x;
		int res = kth_ancesstor(x, k);
		if (res != -1) {
			res++;
		}
		cout << res << "\n";
	}
    return 0;
}
