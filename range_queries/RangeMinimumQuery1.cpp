#include <bits/stdc++.h>

using namespace std;

void fastscan(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}

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

typedef long long int ll;

class RMQ {
private:
    int n,k;
    vector<vector<int>> st;
    vector<int> log;
public:
    RMQ(int n, vector<int>& a) {
        this->n = n;

        log.reserve(n+1);
        log[1] = 0;
        for (int i = 2; i <= n; ++i) {
            log[i] = log[i/2] + 1;
        }

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
                    st[i][j] = min(st[i][j-1], st[i+prev][j-1]);
                }
            }
        }
    }

    int getMin(int l, int r) {
        int j = log[r-l+1];
        return min(st[l][j], st[r-(1<<j)+1][j]);
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    readArray(a,n);
    RMQ rmq(n,a);
    for (int i = 0; i < q; ++i) {
        int l,r;
        cin >> l >> r;
        cout << rmq.getMin(l-1, r-1) << endl;
    }
    return 0;
}