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

    int n;
    cin >> n;

    vector<pair<int,int>> vec;
    for (int i = 0; i < n; ++i) {
        int a,e;
        cin >> a >> e;
        vec.emplace_back(make_pair(a,0));
        vec.emplace_back(make_pair(e,1));
    }

    sort(vec.begin(), vec.end());
    int ans = 0, cur = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].second == 0) {
            ans = max(ans, ++cur);
        }
        else {
            --cur;
        }
    }
    cout << ans;
    return 0;
}