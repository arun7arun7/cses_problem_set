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

    int x,n;
    cin >> x >> n;
    vector<int> p(n);
    readArray(p,n);

    set<int> points = {0,x};
    multiset<int> len = {x};

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        auto upper = points.upper_bound(p[i]);
        auto lower = prev(upper);

        len.erase(len.find(*upper - *lower));
        len.insert(*upper - p[i]);
        len.insert(p[i] - *lower);

        points.insert(p[i]);

        ans[i] = *len.rbegin();
    }
    printArray(ans, ' ');
    return 0;
}