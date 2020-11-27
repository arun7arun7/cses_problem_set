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
ll INF = 1e18;

class Graph {
private:

    struct Edge {
        int start, end;
        int weight;

        Edge(int start, int anEnd, int weight) : start(start), end(anEnd), weight(weight) {}
    };

    int n;
    vector<Edge> edges;
    vector<vector<Edge>> neighbors;

public:
    Graph(int n) {
        this->n = n;
        neighbors.reserve(n);
    }

    void addEdge(int st, int end, int weight) {
        Edge edge = {st,end,weight};
        edges.push_back(edge);
        neighbors[st].push_back(edge);
    }

    void dfs(int i, vector<bool>& visited) {
        visited[i] = true;
        for (Edge& edge: neighbors[i]) {
            int neighbor = edge.end;
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    void negative_cycle() {
        vector<bool> visited(n, false);
        vector<int> representative;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                representative.push_back(i);
                dfs(i,visited);
            }
        }
        negative_cycle(representative);
    }

    void negative_cycle(vector<int>& representative) {
        vector<ll> d(n, INF);
        vector<int> p(n,-1);
        for (int r : representative) {
            d[r] = 0;
        }

        int x;
        for (int i = 0; i < n; ++i) {
            x = -1;
            for (Edge& edge : edges) {
                if (d[edge.start] + edge.weight < d[edge.end]) {
                    d[edge.end] = d[edge.start] + edge.weight;
                    p[edge.end] = edge.start;
                    x = edge.end;
                }
            }
        }

        if (x == -1) {
            cout << "NO" << endl;
        }
        else {
            for (int i = 0; i < n; ++i)
                x = p[x];
            vector<int> cycle;
            for (int v = x; ; v = p[v]) {
                cycle.push_back(v+1);
                if (v == x && cycle.size() > 1) {
                    break;
                }
            }
            reverse(cycle.begin(), cycle.end());
            cout << "YES" << endl;
            printArray(cycle, ' ');
        }
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    Graph graph(n);
    for (int i = 0; i < m; ++i) {
        int a,b,w;
        cin >> a >> b >> w;
        graph.addEdge(a-1,b-1,w);
    }

    graph.negative_cycle();
    return 0;
}