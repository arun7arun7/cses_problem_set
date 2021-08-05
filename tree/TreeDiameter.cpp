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

int n, res;
vector<vector<int>> neighbors;
vector<int> height;

void dfs(int cur, int p) {
	int mx = -1, smx = -1;
	height[cur] = 0;
	for (int neighbor : neighbors[cur]) {
		if (neighbor != p) {
			dfs(neighbor, cur);
			if (mx == -1 || height[neighbor] > height[mx]) {
				mx = neighbor;
			}
		}
	}
	if (mx == -1) {
		return;
	}
	height[cur] = 1 + height[mx];
	for (int neighbor : neighbors[cur]) {
		if (neighbor != p && neighbor != mx) {
			if (smx == -1 || height[neighbor] >  height[smx]) {
				smx = neighbor;
			}
		}
	}
	if (smx == -1) {
		res = max(res, height[cur]);
	}
	else {
		res = max(res, height[cur] + height[smx] + 1);
	}
}

#define ONLINE_JUDGE
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	neighbors.assign(n, vector<int>());
	height.reserve(n);
	for (int i = 0; i < n-1; i++) {
		int a,b;
		cin >> a >> b;
		--a;--b;
		neighbors[a].push_back(b);
		neighbors[b].push_back(a);
	}
	res = 0;
	dfs(0,-1);
	cout << res << "\n";
    return 0;
}
