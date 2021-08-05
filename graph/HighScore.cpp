#include <bits/stdc++.h>

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
#define vi vector
#define pp pair

template <typename T> void read(T& t) { cin >> t;}
template<typename T, typename... Args> void read(T& t, Args&... args) { cin >> t; read(args...);}
template <typename T> void print(T t) { cout << t;}
template<typename T, typename... Args> void print(T t, Args... args) { cout << t ; print(args...);}

struct Edge {
    int a, b, c;
};

int n,m;
ll inf = 1e18;
//vi<vi<pp<int,int>>> neighbors;
vi<Edge> edges;
vi<ll> dist;

// #define ONLINE_JUDGE
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    read(n,m);
    edges.resize(m);
    dist.assign(n, inf);
    fo(i, 0, m) {
        int a,b,x;
        read(a, b, x);
        --a; --b;
        edges[i] = {a, b, -x};
    }

    dist[0] = 0;
    fo(i, 0, n-1) {
        fo(j, 0, m) {
            if(dist[edges[j].a] != inf && dist[edges[j].b] > dist[edges[j].a] + edges[j].c) {
                dist[edges[j].b] = dist[edges[j].a] + edges[j].c;
            }
        }
    }
    debug(dist);
    ll init = -dist[n-1];
    fo(i, 0, n) {
        fo(j, 0, m) {
            if(dist[edges[j].a] != inf && dist[edges[j].b] > dist[edges[j].a] + edges[j].c) {
                dist[edges[j].b] = dist[edges[j].a] + edges[j].c;
            }
        }
    }
    debug(dist);
    debug(init, -dist[n-1]);
    if(init < -dist[n-1]) {
        print(-1, "\n");
    }
    else {
        print(-dist[n-1], "\n");
    }
    return 0;
}
