#include <bits/stdc++.h>
#define ONLINE_JUDGE
#pragma GCC target("popcnt")

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

#define fo(i, k, n) for(int i=k; k<n?i<n:i>n; k<n?++i:--i)
#define flush() cout << flush;
#define pb push_back


template <typename T> void read(T& t) { cin >> t;}
template<typename T, typename... Args> void read(T& t, Args&... args) { cin >> t; read(args...);}
template <typename T> void print(T t) { cout << t;}
template<typename T, typename... Args> void print(T t, Args... args) { cout << t ; print(args...);}

const int nn = 3000;

ll nc2(int n) {
    return 1LL*n*(n-1)/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<bitset<nn>> a(n);
    ll res = 0;
    fo(i, 0, n) {
        string s;
        cin >> s;
        debug(s);
        bitset<nn> bb(s);
        fo(j, 0, i) {
            res += nc2((bb & a[j]).count());
        }
        a[i] = bb;
    }
    cout << res << "\n";
    return 0;
}
