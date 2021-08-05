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

int mod = 1e9+7, sq;
ll inv2, n;

ll power(ll a, ll m) {
	if (m == 0) {
		return 1;
	}
	if (m == 1) {
		return a % mod;
	}
	ll val = power(a, m/2);
	ll res = (val * val) % mod;
	if (m & 1) {
		(res *= a) %= mod;
	}
	return res;
}

ll modInv(ll a, ll m) {
	return power(a, m-2);
}

ll sum(ll v) {
	v %= mod;
	return (((v * (v + 1)) % mod ) * inv2) % mod;
}

ll nearest(ll a, ll b, ll d) {
	ll v1 = a / d, v2 = b / d;
	if (a % d != 0) {
		v1++;
	}
	v1 %= mod; v2 %= mod;
	ll res = (((v2 - v1 + 1 + mod) % mod) * d) % mod;
	(res += (sum(v2) - sum(v1-1) + mod)) %= mod;
	return res;
}

// #define ONLINE_JUDGE
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin >> n;
	
	sq = (int)sqrt(n);
	inv2 = modInv(2, mod);
	ll res1 = 0, res2 = 0;
	debug(sq, inv2);
	for (int i = 1; i <= sq; i++) {
		// ll v = n / i, s = v * i, ne = nearest(sq+1, n, i);
		(res1 += ((ll)(sq / i) * i)) %= mod;
		(res2 += nearest(sq+1, n, i)) %= mod;
		debug(i, res1, res2);
	}
	
	ll res = (res1 + (res2 * inv2) % mod) % mod;
	cout << res << "\n";
    return 0;
}
