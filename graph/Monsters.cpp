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
        char direction;
    };

    int n;
    vector<vector<Edge>> neighbors;

public:
    Graph(int n) {
        this->n = n;
        neighbors.reserve(n);
    }

    void addEdge(int st, int end, char direction) {
        Edge edge = {st,end,direction};
        neighbors[st].push_back(edge);
    }

    vector<int> multi_source_bfs(unordered_set<int>& monsters) {
        vector<int> shortest_path(n, -1);
        vector<bool> visited(n, false);
        queue<pair<int,int>> q;
        for (int m : monsters) {
            q.push(make_pair(m, 0));
            visited[m] = true;
        }
        while (!q.empty()) {
            pair<int,int> front = q.front();
            q.pop();
            int cur_node = front.first;
            shortest_path[cur_node] = front.second;
            for (Edge& edge : neighbors[cur_node]) {
                int neighbor = edge.end;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(make_pair(neighbor, front.second + 1));
                }
            }
        }
        return shortest_path;
    }

    void print_path(int start, unordered_set<int>& monsters, unordered_set<int>& end_vertices) {
        vector<int> monster_min_reaching_time = multi_source_bfs(monsters);
        queue<pair<int,int>> queue;
        queue.push(make_pair(start,0));
        vector<bool> added(n, false);
        vector<Edge*> parent(n);
        added[start] = true;
        parent[start] = nullptr;
        while (!queue.empty()) {
            pair<int,int> pair = queue.front();
            int cur_node = pair.first;
            if (end_vertices.find(cur_node) != end_vertices.end()) {
                cout << "YES" << endl;
                cout << pair.second << endl;
                string path;
                int node = cur_node;
                while (parent[node] != nullptr) {
                    path.push_back(parent[node]->direction);
                    node = parent[node]->start;
                }
                reverse(path.begin(),path.end());
                cout << path << endl;
                return;
            }
            queue.pop();
            for (Edge& edge : neighbors[cur_node]) {
                int neighbor = edge.end;
                if (!added[neighbor]) {
                    added[neighbor] = true;
                    if (monster_min_reaching_time[neighbor] == -1 || monster_min_reaching_time[neighbor] > pair.second+1) {
                        queue.push(make_pair(neighbor, pair.second+1));
                        parent[neighbor] = &edge;
                    }
                }
            }
        }
        cout << "NO" << endl;
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
            if (input[i][j] != '#') {
                nodes++;
            }
        }
    }

    Graph graph(nodes);
    vector<vector<int>> node_num(n, vector<int>(m, -1));
    int cur_node = 0, start;
    unordered_set<int> monsters,end_vertices;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (input[i][j] != '#') {
                node_num[i][j] = cur_node++;
                if (input[i][j] == 'A') {
                    start = node_num[i][j];
                }
                if (input[i][j] == 'M') {
                    monsters.insert(node_num[i][j]);
                }
                if (i == n-1 || j == m-1 || i == 0 || j == 0) {
                    end_vertices.insert(node_num[i][j]);
                }

                if (i-1 >= 0 && input[i-1][j] != '#') {
                    graph.addEdge(node_num[i][j], node_num[i-1][j], 'U');
                    graph.addEdge(node_num[i-1][j], node_num[i][j], 'D');
                }
                if (j-1 >= 0 && input[i][j-1] != '#') {
                    graph.addEdge(node_num[i][j], node_num[i][j-1], 'L');
                    graph.addEdge(node_num[i][j-1], node_num[i][j], 'R');
                }
            }
        }
    }

    graph.print_path(start, monsters, end_vertices);
    return 0;
}