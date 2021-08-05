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

class SegmentTree {
private:
    struct Node {
        ll sum, max_prefix_sum, max_suffix_sum, max_subarray_sum;

        Node(ll sum, ll max_prefix_sum, ll max_suffix_sum, ll max_subarray_sum) {
			this->sum = sum;
			this->max_prefix_sum = max_prefix_sum;
			this->max_suffix_sum = max_suffix_sum;
			this->max_subarray_sum = max_subarray_sum;
		} 
    };

    vector<Node*> st;
    int n, size;

    void build(int cur, int beg, int end, vector<int>& arr) {
        if (beg == end) {
            st[cur] = new Node(arr[beg], max(arr[beg], 0), max(arr[beg], 0), max(arr[beg], 0));
            return;
        }
        int mid = (beg + end) / 2;
        build(2*cur, beg, mid, arr);
        build(2*cur+1, mid+1, end, arr);
        
        st[cur] = new Node(st[2*cur]->sum + st[2*cur+1]->sum, 
							max(st[2*cur]->max_prefix_sum, st[2*cur]->sum + st[2*cur+1]->max_prefix_sum), 
							max(st[2*cur+1]->max_suffix_sum, st[2*cur+1]->sum + st[2*cur]->max_suffix_sum), 
							max(st[2*cur]->max_subarray_sum, max(st[2*cur+1]->max_subarray_sum, st[2*cur]->max_suffix_sum + st[2*cur+1]->max_prefix_sum)));
    }

    void update(int cur, int beg, int end, int& ind, int& ele) {
        if (beg == end) {
            st[cur]->sum = ele;
            st[cur]->max_prefix_sum = max(ele, 0);
            st[cur]->max_suffix_sum = max(ele, 0);
            st[cur]->max_subarray_sum = max(ele, 0);
            return;
        }
        int mid = (beg + end) / 2;
        if (ind <= mid) {
            update(2*cur, beg, mid, ind, ele);
        }
        else {
            update(2*cur+1, mid+1, end, ind, ele);
        }
        st[cur]->sum = st[2*cur]->sum + st[2*cur+1]->sum;
        st[cur]->max_prefix_sum = max(st[2*cur]->max_prefix_sum, st[2*cur]->sum + st[2*cur+1]->max_prefix_sum);
        st[cur]->max_suffix_sum = max(st[2*cur+1]->max_suffix_sum, st[2*cur+1]->sum + st[2*cur]->max_suffix_sum);
        st[cur]->max_subarray_sum = max(st[2*cur]->max_subarray_sum, max(st[2*cur+1]->max_subarray_sum, st[2*cur]->max_suffix_sum + st[2*cur+1]->max_prefix_sum));
    }

public:
    SegmentTree(vector<int>& arr, int n) {
        this->n = n;
        int x = ceil(log2(n));
        size = 2*pow(2,x) + 5;
        st.reserve(size);
        build(1, 0, n-1, arr);
    }

    void update(int ind, int ele) {
        update(1, 0, n-1, ind, ele);
    }

    ll query() {
        return st[1]->max_subarray_sum;
    }

};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	readArray(a, n);
	
	SegmentTree st(a, n);
	for (int i = 0; i < m; i++) {
		int k,x;
		cin >> k >> x;
		st.update(k-1, x);
		cout << st.query() << "\n";
	}
    return 0;
}
