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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    vector<vector<int>> ps(n+1, vector<int>(n+1, 0));
	vector<vector<int>> input(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char ch;
			cin >> ch;
			int val = 0;
			if (ch == '*') {
				val = 1;
			}
			input[i][j] = val;
			ps[i][j] = ps[i][j-1] + ps[i-1][j] - ps[i-1][j-1] + input[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		int y1,x1,y2,x2;
		cin >> y1 >> x1 >> y2 >> x2;
		int ans = ps[y2][x2] - ps[y1-1][x2] - ps[y2][x1-1] + ps[y1-1][x1-1];
		cout << ans << "\n";
	}
    return 0;
}
