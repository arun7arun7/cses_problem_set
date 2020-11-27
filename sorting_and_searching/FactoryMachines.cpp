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

    int n,t;
    cin >> n >> t;
    vector<int> k(n);
    readArray(k,n);

    ll beg = 1, finish = 1e18 + 5;
    ll ans;
    while (beg <= finish) {
       ll mid = (beg + finish) / 2;
       ll product_made = 0;
       bool t_made = false;
        for (int i = 0; i < n; ++i) {
            product_made += mid/k[i];
            if (product_made >= t) {
                t_made = true;
                break;
            }
        }
        if (t_made) {
            finish = mid-1;
            ans = mid;
        }
        else {
            beg = mid+1;
        }
    }
    cout << ans;
    return 0;
}