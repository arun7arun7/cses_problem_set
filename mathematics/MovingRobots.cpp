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

const int n = 64, m = 8;
double p[m][m][n+1];
int cnt[m][m];

vector<double> construct(vector<vector<double>>& polynomial) {
	int sz = polynomial.size();
	vector<double> res(n+1);
	for (int power = 0; power <= n; power++) {
		res[power] = polynomial[0][power];
	}
	for (int i = 1; i < sz; i++) {
		vector<double> cur(n+1,0);
		for (int p1 = 0; p1 <= n; p1++) {
			for (int p2 = 0; p2 <= n; p2++) {
				if (p1+p2 <= n) {
					cur[p1+p2] += res[p1] * polynomial[i][p2];
				}
			}
		}
		for (int power = 0; power <= n; power++) {
			res[power] = cur[power];
		}
	}
	return res;
}

// #define ONLINE_JUDGE
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int k;
	cin >> k;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			p[i][j][1] = 1;
			if (i-1 >= 0) cnt[i][j]++;
			if (j-1 >= 0) cnt[i][j]++;
			if (i+1 < m) cnt[i][j]++;
			if (j+1 < m) cnt[i][j]++;
			// debug(i,j,cnt[i][j]);
		}
	}
	for (int turn = 1; turn <= k; turn++) {
		double cur[m][m][n+1];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				
				vector<vector<double>> polynomial(cnt[i][j], vector<double>(n+1, 0));
				int c = 0;
				
				// current cell 
				/*
				double dir = (double)1 / cnt[i][j];
				for (int power = 0; power <= n; power++) {
					for (int val = 0; val <= n; val++) {
						if (val >= power) {
							polynomial[c][power] += p[i][j][val] * pow(dir, power) * pow(1-dir, val-power);
						}
					} 
				}
				c++;
				* */
				
				// bottom
				if (i-1 >= 0) {
					int ind = i-1;
					double dir = (double)1 / cnt[ind][j];
					for (int power = 0; power <= n; power++) {
						for (int val = 0; val <= n; val++) {
							if (val >= power) {
								polynomial[c][power] += p[ind][j][val] * pow(dir, power) * pow(1-dir, val-power);
							}
						} 
					}
					c++;
				}
				
				if (i+1 < m) {
					int ind = i+1;
					double dir = (double)1 / cnt[ind][j];
					for (int power = 0; power <= n; power++) {
						for (int val = 0; val <= n; val++) {
							if (val >= power) {
								polynomial[c][power] += p[ind][j][val] * pow(dir, power) * pow(1-dir, val-power);
							}
						} 
					}
					c++;
				}
				
				if (j-1 >= 0) {
					int ind = j-1;
					double dir = (double)1 / cnt[i][ind];
					for (int power = 0; power <= n; power++) {
						for (int val = 0; val <= n; val++) {
							if (val >= power) {
								polynomial[c][power] += p[i][ind][val] * pow(dir, power) * pow(1-dir, val-power);
							}
						} 
					}
					c++;
				}
				
				if (j+1 < m) {
					int ind = j+1;
					double dir = (double)1 / cnt[i][ind];
					for (int power = 0; power <= n; power++) {
						for (int val = 0; val <= n; val++) {
							if (val >= power) {
								polynomial[c][power] += p[i][ind][val] * pow(dir, power) * pow(1-dir, val-power);
							}
						} 
					}
					c++;
				}
				
				// debug(polynomial);
				vector<double> cur_cell_p = construct(polynomial);
				debug(turn,i,j, cur_cell_p);
				
				for (int power = 0; power <= n; power++) {
					cur[i][j][power] = cur_cell_p[power];
				}
			}
		}
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				for (int val = 0; val <= n; val++) {
					p[i][j][val] = cur[i][j][val];
				}
			}
		}
	}
	
	double res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			res += p[i][j][0];
		}
	}
	
	cout << fixed << setprecision(10) << res << "\n";
    return 0;
}
