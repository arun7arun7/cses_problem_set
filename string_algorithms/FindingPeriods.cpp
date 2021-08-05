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

const int p = 31, p2 = 53, m = 1e9 + 9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string s;
	cin >> s;
	
	int n = s.size();
	vector<ll> hash(n+1), pow(n+1);
	hash[0] = 0;
	pow[0] = 1;
	for (int i = 1; i <= n; i++) {
		pow[i] = (p* pow[i-1]) % m;
	}
	for (int i = 1; i <= n; i++) {
		hash[i] = (hash[i-1] + ((s[i-1] - 'a' + 1) * pow[i-1])) % m;
	}
	
	vector<ll> hash2(n+1), pow2(n+1);
	hash2[0] = 0;
	pow2[0] = 1;
	for (int i = 1; i <= n; i++) {
		pow2[i] = (p2* pow2[i-1]) % m;
	}
	for (int i = 1; i <= n; i++) {
		hash2[i] = (hash2[i-1] + ((s[i-1] - 'a' + 1) * pow2[i-1])) % m;
	}
	
	vector<int> res;
	for (int k = 1; k <= n; k++) {
		ll h1_suffix = (hash[n] - hash[k] + m) % m;
		ll h1_prefix = (hash[n-k] * pow[k]) % m;
		
		ll h2_suffix = (hash2[n] - hash2[k] + m) % m;
		ll h2_prefix = (hash2[n-k] * pow2[k]) % m;
		
		if (h1_suffix == h1_prefix && h2_suffix == h2_prefix) {
			res.push_back(k);
		}
	}
	
	printArray(res, ' ');
    return 0;
}
