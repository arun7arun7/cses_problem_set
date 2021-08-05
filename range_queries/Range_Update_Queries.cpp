#include <bits/stdc++.h>

using namespace std;

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

typedef long long int ll;
const int inf = 1e9+5;
const ll INF = 1e18;

class SegmentTree {
private:
    struct Node {
        ll val;
        ll push_val;
        
        Node(ll val) : val(val), push_val(0) {}
    };

    vector<Node*> st;
    int n, size;

    void build(int cur, int beg, int end, vector<int>& arr) {
        if (beg == end) {
            st[cur] = new Node(arr[beg]);
            return;
        }
        int mid = (beg + end) / 2;
        build(2*cur, beg, mid, arr);
        build(2*cur+1, mid+1, end, arr);
        st[cur] = new Node(st[2*cur]->val + st[2*cur+1]->val);
    }
    
    void push(int cur, int beg, int end) {
		st[2*cur]->val += st[cur]->push_val;
		st[2*cur+1]->val += st[cur]->push_val;
		st[2*cur]->push_val += st[cur]->push_val;
		st[2*cur+1]->push_val += st[cur]->push_val;
		st[cur]->push_val = 0;
	}

    void update(int cur, int beg, int end, int& l, int& r, int& delta) {
        if (beg > r || end < l) {
			return;
		}
		if (beg >= l && end <= r) {
			st[cur]->val += delta;
			st[cur]->push_val += delta;
			return;
		}
		push(cur, beg, end);
		int mid = (beg + end) / 2;
		update(2*cur, beg, mid, l, r, delta);
		update(2*cur+1, mid+1, end, l, r, delta);
        st[cur]->val = st[2*cur]->val + st[2*cur+1]->val;
    }
    
    ll query(int cur, int beg, int end, int& l, int& r) {
        if (beg > r || end < l) {
            return 0;
        }
        if (beg >= l && end <= r) {
            return st[cur]->val;
        }
        push(cur, beg, end);
        int mid = (beg + end) / 2;
        return (query(2*cur, beg, mid, l, r) + query(2*cur+1, mid+1, end, l, r));
    }

public:
    SegmentTree(vector<int>& arr, int n) {
        this->n = n;
        int x = ceil(log2(n));
        size = 2*pow(2,x) + 5;
        st.reserve(size);
        build(1, 0, n-1, arr);
    }

    void update(int l, int r, int delta) {
        update(1, 0, n-1, l, r, delta);
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

};






int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    readArray(arr, n);

    SegmentTree segmentTree(arr, n);

    for (int i = 0; i < q; ++i) {
        int c;
        cin >> c;
        if (c == 1) {
            int a,b,u;
            cin >> a >> b >> u;
            segmentTree.update(a-1, b-1 ,u);
        } else {
            int k;
            cin >> k;
            cout << segmentTree.query(k-1, k-1) << "\n";
        }
    }
    return 0;
}
