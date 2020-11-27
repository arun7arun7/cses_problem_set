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

class Graph {
private:

    struct Edge {
        int start, end;
    };

    int n;
    vector<vector<Edge>> neighbors;

public:
    Graph(int n) {
        this->n = n;
        neighbors.reserve(n);
    }

    void addEdge(int st, int end) {
        Edge edge = {st,end};
        neighbors[st].push_back(edge);
        edge = {end, st};
        neighbors[end].push_back(edge);
    }

    void print_shortest_path(int a, int b) {
        queue<pair<int,int>> queue;
        queue.push(make_pair(a,1));
        vector<bool> added(n, false);
        vector<Edge*> parent(n);
        added[a] = true;
        parent[a] = nullptr;
        while (!queue.empty()) {
            pair<int,int> pair = queue.front();
            if (pair.first == b) {
                cout << pair.second << endl;
                vector<int> path;
                path.push_back(n);
                int node = n-1;
                while (parent[node] != nullptr) {
                    path.push_back(parent[node]->start+1);
                    node = parent[node]->start;
                }
                reverse(path.begin(),path.end());
                printArray(path,' ');
                return;
            }
            queue.pop();
            int cur_node = pair.first;
            for (Edge& edge : neighbors[cur_node]) {
                int neighbor = edge.end;
                if (!added[neighbor]) {
                    added[neighbor] = true;
                    queue.push(make_pair(neighbor, pair.second+1));
                    parent[neighbor] = &edge;
                }
            }
        }
        cout << "IMPOSSIBLE" << endl;
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
        int a,b;
        cin >> a >> b;
        graph.addEdge(a-1,b-1);
    }

    graph.print_shortest_path(0,n-1);
    return 0;
}