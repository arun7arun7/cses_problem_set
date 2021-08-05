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

class RMQ {
private:
    int n,k;
    vector<vector<int>> st;
public:
    RMQ(int n, vector<int>& a) {
        this->n = n;

        k = (int )log2(n)+1;
        st.assign(n, vector<int>(k));
        for (int i = 0; i < n; ++i) {
            st[i][0] = a[i];
        }
        for (int j = 1; j < k; j++) {
            int l = 1 << j;
            int prev = 1 << (j-1);
            for (int i = 0; i < n; ++i) {
                if (i+l-1 < n) {
                    st[i][j] = max(st[i][j-1], st[i+prev][j-1]);
                }
            }
        }
    }

    int getMax(int l, int r) {
        int j = log2(r-l+1);
        return max(st[l][j], st[r-(1<<j)+1][j]);
    }
};

int n;
vector<vector<int>> neighbors;
vector<int> dp;
vector<int> height;
vector<int> parent;
vector<int> result;

void dfs(int cur,int p) {
	height[cur] = 0;
	parent[cur] = p;
	for (int neighbor : neighbors[cur]) {
		if (neighbor != p) {
			dfs(neighbor, cur);
			height[cur] = max(height[cur], 1 + height[neighbor]);
		}
	}
	debug(cur, height[cur]);
}

void dfs2(int cur, int p) {
	debug(2, cur);
	vector<int> child_height, child;
	for (int neighbor : neighbors[cur]) {
		if (neighbor != p) {
			child_height.push_back(height[neighbor]);
			child.push_back(neighbor);
		}
	}
	int sz = child.size();
	debug(child_height, child, sz);
	RMQ* rmq = nullptr;
	if (sz > 0) {
		rmq = new RMQ(sz, child_height);
	}
	for (int i = 0; i < sz; i++) {
		int left = -1, right = -1;
		if (i-1 >= 0) {
			left = rmq->getMax(0, i-1);
		}
		if (i+1 < sz) {
			right = rmq->getMax(i+1, sz-1);
		}
		dp[child[i]] = max(1 + dp[cur], max(1 + left, 1 + right));
		debug(left, right, dp[child[i]]);
	}
	result[cur] = max(height[cur], 1 + dp[cur]);
	debug(result[cur]);
	
	for (int neighbor : neighbors[cur]) {
		if (neighbor != p) {
			dfs2(neighbor, cur);
		}
	}
	debug(height, result);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	debug(n);
	neighbors.assign(n, vector<int>());
	dp.reserve(n);
	height.reserve(n);
	parent.reserve(n);
	result.reserve(n);
	for (int i = 0; i < n-1; i++) {
		int a,b;
		cin >> a >> b;
		--a;--b;
		neighbors[a].push_back(b);
		neighbors[b].push_back(a);
	}
	debug(neighbors);
	dp[0] = -1;
	dfs(0,-1);
	debug(height);
	dfs2(0, -1);
	debug(height, result);
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
    return 0;
}
