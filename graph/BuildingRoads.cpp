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

    vector<int> connected_components() {
        vector<bool> visited(n, false);
        int res = 0;
        vector<int> representative;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                representative.push_back(i);
                res++;
                dfs(i,visited);
            }
        }
        return representative;
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

    vector<int> representative = graph.connected_components();
    cout << representative.size() - 1 << endl;
    for (int i = 1; i < representative.size(); ++i) {
        cout << (representative[i-1]+1) <<  " " << (representative[i]+1) << endl;
    }
    return 0;
}