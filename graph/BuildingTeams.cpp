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

    bool two_colorable(int node, int color, vector<bool> &visited, vector<int>& colors) {
        visited[node] = true;
        colors[node] = color;
        int neighbor_color = color == 1 ? 2 : 1;
        for (int neighbor : neighbors[node]) {
            if (!visited[neighbor]) {
                if (!two_colorable(neighbor, neighbor_color, visited, colors)) {
                    return false;
                }
            }
            else {
                if (colors[neighbor] == colors[node]) {
                    return false;
                }
            }
        }
        return true;
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

    void two_colorable() {
        vector<bool> visited(n, false);
        vector<int> colors(n);
        bool two_colorable_graph = true;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (!two_colorable(i,1,visited, colors)) {
                    two_colorable_graph = false;
                    break;
                }
            }
        }
        if (two_colorable_graph) {
            printArray(colors, ' ');
        }
        else {
            cout << "IMPOSSIBLE" << endl;
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

    graph.two_colorable();
    return 0;
}