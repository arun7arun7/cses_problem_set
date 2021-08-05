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

vector<int> st;
int n,m;

void build(int i, int beg, int end, vector<int>& h) {
	if (beg == end) {
		st[i] = (h[beg]);
		return;
	}
	int mid = (beg + end) / 2;
	build(2*i, beg, mid, h);
	build(2*i+1, mid+1, end, h);
	st[i] = max(st[2*i], st[2*i+1]);
}

int update(int i, int beg, int end, int val) {
	if (beg == end) {
		st[i] = st[i] - val;
		return beg;
	}
	int mid = (beg  + end) / 2;
	int res;
	if (st[2*i] >= val) {
		res = update(2*i, beg, mid, val);
	}
	else {
		res = update(2*i+1, mid+1, end, val);
	}
	st[i] = max(st[2*i], st[2*i+1]);
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> m;
	debug(n, m);
	vector<int> h(n), r(m);
	readArray(h, n);
	readArray(r, m);
	debug(h, r);
	
	st.resize(4*n);
	build(1, 0, n-1, h);
	for (int i = 0; i < m; i++) {
		if (st[1] < r[i]) {
			cout << 0 << "\n";
			continue;
		}
		int res = update(1, 0, n-1, r[i]);
		cout << res + 1 << "\n";
	}
    return 0;
}
