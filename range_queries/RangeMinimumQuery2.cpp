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
const int inf = 2e9;
const ll INF = 1e18;

class SegmentTree {
private:
    struct Node {
        int val;

        Node(int val) : val(val) {}
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
        st[cur] = new Node(min(st[2*cur]->val, st[2*cur+1]->val));
    }

    void update(int cur, int beg, int end, int& ind, int& ele) {
        if (beg == end) {
            st[cur]->val = ele;
            return;
        }
        int mid = (beg + end) / 2;
        if (ind <= mid) {
            update(2*cur, beg, mid, ind, ele);
        }
        else {
            update(2*cur+1, mid+1, end, ind, ele);
        }
        st[cur] = new Node(min(st[2*cur]->val, st[2*cur+1]->val));
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

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    int query(int cur, int beg, int end, int& l, int& r) {
        if (beg > r || end < l) {
            return inf;
        }
        if (beg >= l && end <= r) {
            return st[cur]->val;
        }
        int mid = (beg + end) / 2;
        return min(query(2*cur, beg, mid, l, r), query(2*cur+1, mid+1, end, l, r));
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    readArray(a, n);

    SegmentTree segmentTree(a, n);

    for (int i = 0; i < q; ++i) {
        int c;
        cin >> c;
        if (c == 1) {
            int k,u;
            cin >> k >> u;
            segmentTree.update(k-1, u);
        } else {
            int l,r;
            cin >> l >> r;
            cout << segmentTree.query(l-1, r-1) << "\n";
        }
    }
    return 0;
}