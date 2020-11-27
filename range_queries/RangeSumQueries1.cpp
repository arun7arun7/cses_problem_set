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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    readArray(a,n);
    vector<ll> prefix_sum(n+1);
    prefix_sum[0] = 0;
    for (int i = 1; i <= n ; ++i) {
        prefix_sum[i] = prefix_sum[i-1] + a[i-1];
    }
    for (int i = 0; i < q; ++i) {
        int l,r;
        cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l-1] << endl;
    }
    return 0;
}