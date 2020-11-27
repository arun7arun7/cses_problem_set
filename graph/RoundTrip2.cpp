#include <bits/stdc++.h>

using namespace std;

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
    vector<int> ancestors;

public:
    Graph(int n) {
        this->n = n;
        neighbors.reserve(n);
        ancestors.reserve(n);
    }

    void addEdge(int st, int end) {
        neighbors[st].push_back(end);
    }

    bool find_cycle(int cur, int parent, vector<bool>& visited, unordered_set<int>& cur_ancestors) {
        ancestors[cur] = parent;
        cur_ancestors.insert(cur);
        visited[cur] = true;
        for (int neighbor : neighbors[cur]) {
            if (cur_ancestors.find(neighbor) != cur_ancestors.end()) {
                // print cycle
                vector<int> cycle;
                cycle.push_back(neighbor+1);
                for (int v = cur; ; v = ancestors[v]) {
                    cycle.push_back(v+1);
                    if (v == neighbor) {
                        break;
                    }
                }
                reverse(cycle.begin(), cycle.end());
                cout << cycle.size() << endl;
                printArray(cycle, ' ');
                return true;
            }
            if (!visited[neighbor]) {
                if (find_cycle(neighbor, cur, visited, cur_ancestors)) {
                    return true;
                }
            }
        }
        cur_ancestors.erase(cur);
        return false;
    }

    // find cycles of size >= 2 in directed graph
    void find_cycle() {
        vector<bool> visited(n, false);
        unordered_set<int> cur_ancestors;
        bool f = false;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (find_cycle(i, -1, visited, cur_ancestors)) {
                    f = true;
                    break;
                }
            }
        }
        if (!f) {
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

    graph.find_cycle();
    return 0;
}