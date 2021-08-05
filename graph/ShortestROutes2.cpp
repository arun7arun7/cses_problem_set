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

int n,m,q;
ll inf = 1e18;

#define ONLINE_JUDGE
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q; 
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, inf));
    for(int i=1; i<=n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (ll)c);
        dist[b][a] = min(dist[a][b], (ll)c);
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dist[i][j] > dist[i][k]+dist[k][j]) {
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for(int i=0; i<q; i++) {
        int a,b;
        cin >> a >> b;
        if(dist[a][b] == inf) {
            cout << -1 << "\n";
            continue;
        }
        cout << dist[a][b] << "\n";
    }
    
    return 0;
}
