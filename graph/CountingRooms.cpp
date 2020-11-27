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

    void dfs(int node, vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : neighbors[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
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

    int number_of_connected_components() {
        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                res++;
                dfs(i,visited);
            }
        }
        return res;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<string> input(n);
    int nodes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        for (int j = 0; j < m; ++j) {
            if (input[i][j] == '.') {
                nodes++;
            }
        }
    }

    Graph graph(nodes);
    vector<vector<int>> node_num(n, vector<int>(m, -1));
    int cur_node = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (input[i][j] == '.') {
                node_num[i][j] = cur_node++;
                if (i-1 >= 0 && input[i-1][j] == '.') {
                    graph.addEdge(node_num[i][j], node_num[i-1][j]);
                }
                if (j-1 >= 0 && input[i][j-1] == '.') {
                    graph.addEdge(node_num[i][j], node_num[i][j-1]);
                }
            }
        }
    }

    cout << graph.number_of_connected_components();
    return 0;
}