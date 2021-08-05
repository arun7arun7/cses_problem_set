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

// #define ONLINE_JUDGE

class Frac {
	
public:
	ll n,d;
	int sgn;
	
	ll gcd(ll a, ll b) {
		if (a < b) {
			swap(a, b);
		}
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}
	
	int sign(ll& n, ll& d) {
		int sign = 1;
		if (n == 0) {
			d = 1;
			return sign;
		}
		if (n < 0) {
			n *= -1;
			sign *= -1;
		}
		if (d < 0) {
			d *= -1;
			sign *= -1;
		}
		return sign;
	}
	
	Frac(ll n, ll d) {
		this->sgn = sign(n, d);
		ll g = gcd(n,d);
		this->n = n / g;
		this->d = d / g;
		
	}
	
	Frac operator+(const Frac& r) {
		ll ln = this->sgn * this->n;
		ll ld = this->d;
		ll rn = r.sgn * r.n;
		ll rd = r.d;
		
		ll new_n = (ln * rd) + (ld * rn);
		ll new_d = ld * rd;
		
		Frac tmp(new_n, new_d);
		return tmp;
	}
	
	Frac operator-(const Frac& r) {
		ll ln = this->sgn * this->n;
		ll ld = this->d;
		ll rn = r.sgn * r.n;
		ll rd = r.d;
		
		ll new_n = (ln * rd) - (ld * rn);
		ll new_d = ld * rd;
		
		Frac tmp(new_n, new_d);
		return tmp;
	}
	
	Frac operator*(const Frac& r) {
		ll ln = this->sgn * this->n;
		ll ld = this->d;
		ll rn = r.sgn * r.n;
		ll rd = r.d;
		
		ll new_n = (ln * rn);
		ll new_d = ld * rd;
		
		Frac tmp(new_n, new_d);
		return tmp;
	}
	
	Frac operator/(const Frac& r) {
		ll ln = this->sgn * this->n;
		ll ld = this->d;
		ll rn = r.sgn * r.n;
		ll rd = r.d;
		
		ll new_n = (ln * rd);
		ll new_d = ld * rn;
		
		Frac tmp(new_n, new_d);
		return tmp;
	}
	
	bool operator==(const Frac& r) {
		return this->sgn == r.sgn && this->n == r.n && this->d == r.d;
	}
	
	bool operator<(const Frac& r) {
		/*
		if (this->sgn == -1 && r.sgn == 1) {
			return true;
		}
		if (this->sgn == 1 && r.sgn == -1) {
			return false;
		}
		* */
		
		Frac diff = *this - r;
		if (diff.sgn == -1) {
			return true;
		}
		return false; 
	}
	
	double val() {
		return (double)this->n / this->d;
	}
	
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int x1,y1,x2,y2,x3,y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		
		Frac m(y2 - y1, x2 - x1), c(x2*y1 - x1*y2, x2-x1), lhs(y3,1), x(x3,1);
		Frac rhs = m*x + c;
		
		debug(m.sgn, m.n, m.d);
		debug(c.sgn, c.n, c.d);
		debug(lhs.sgn, lhs.n, lhs.d);
		debug(rhs.sgn, rhs.n, rhs.d);
		
		if (lhs == rhs) {
			cout << "TOUCH" << "\n";
		}
		else if (lhs < rhs) {
			cout << "LEFT" << "\n";
		}
		else {
			cout << "RIGHT" << "\n";
		}
	}
    return 0;
}
