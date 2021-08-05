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

	string s;
	cin >> s;
	
	int n = s.size();
	vector<int> count(26, 0);
	for (int i = 0; i < n; i++) {
		count[s[i] - 'A']++;
	}
	debug(count);
	
	vector<char> res(n);
	if (n % 2 == 0) {
		bool exist = true;
		for (int i = 0; i < 26; i++) {
			if (count[i] & 1) {
				exist = false;
				break;
			}
		}
		
		if (!exist) {
			cout << "NO SOLUTION" << "\n";
			return 0;
		}
		
		
		int i = 0, j = n-1;
		for (int k = 0; k < 26; k++) {
			while (count[k] != 0) {
				res[i] = (char)('A' + k);
				res[j] = (char)('A' + k);
				++i;--j;
				count[k] -= 2;
			}
		}
	}
	else {
		int odd = -1, cnt = 0;
		for (int i = 0; i < 26; i++) {
			if (count[i] & 1) {
				cnt++;
				odd = i;
			}
		}
		
		if (cnt > 1) {
			cout << "NO SOLUTION" << "\n";
			return 0;
		}
		
		int i = 0,j = n-1;
		for (int k = 0; k < 26; k++) {
			while (count[k] != 0 && k != odd) {
				res[i] = (char)('A' + k);
				res[j] = (char)('A' + k);
				++i;--j;
				count[k] -= 2;
				debug(k, res,count);
			}
		}
		debug(i,j,odd,count);
		if (odd != -1) {
			while (i <= j) {
				res[i] = (char)('A' + odd);
				++i;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << res[i];
	}
    return 0;
}

