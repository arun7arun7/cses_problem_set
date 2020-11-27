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
const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<tuple<int,int,ll>> tuples(n);
    for (int i = 0; i < n; ++i) {
        int a,b,w;
        cin >> a >> b >> w;
        tuples[i] = {a,b,w};
    }

    sort(tuples.begin(), tuples.end());

    vector<ll> dp(n);
    for (int i = n-1; i >= 0; --i) {
        int nearest_ind = upper_bound(tuples.begin(), tuples.end(), make_tuple(get<1>(tuples[i]), INF, INF)) - tuples.begin();
        ll next = 0;
        if (nearest_ind != n) {
            next = dp[nearest_ind];
        }
        dp[i] = max(dp[i+1], get<2>(tuples[i]) + next);
    }

    cout << dp[0];
    return 0;
}