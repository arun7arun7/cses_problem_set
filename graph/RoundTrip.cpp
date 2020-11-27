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
    int n;
    vector<vector<int>> neighbors;

    int detect_cycle(int node, int parent, vector<bool> &visited, stack<int>& path) {
        visited[node] = true;
        path.push(node);
        for (int neighbor : neighbors[node]) {
            if (neighbor == parent) {
                continue;
            }
            if (!visited[neighbor]) {
                int cycle = detect_cycle(neighbor, node, visited, path);
                if (cycle != -1) {
                    return cycle;
                }
            }
            else {
                return neighbor;
            }
        }
        path.pop();
        return -1;
    }
public:
    Graph(int n) {
        this->n = n;
        neighbors.reserve(n);
    }

    void addEdge(int a, int b) {
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    void round_trip() {
        vector<bool> visited(n,false);
        bool cycle_found = false;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                stack<int> path;
                int cycle = detect_cycle(i,-1,visited, path);
                if (cycle != -1) {
                    vector<int> cycle_nodes;
                    cycle_nodes.push_back(cycle+1);
                    while (path.top() != cycle) {
                        cycle_nodes.push_back(path.top()+1);
                        path.pop();
                    }
                    cycle_nodes.push_back(cycle+1);

                    cycle_found = true;
                    cout << cycle_nodes.size() << endl;
                    printArray(cycle_nodes, ' ');
                    break;
                }
            }
        }

        if (!cycle_found) {
            cout << "IMPOSSIBLE";
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
        int a,b;
        cin >> a >> b;
        graph.addEdge(a-1,b-1);
    }

    graph.round_trip();
    return 0;
}