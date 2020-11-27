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
ll INF;

class Min_Heap {
public:
    struct Node {
        int key;
        ll priority;

        Node(int key, ll priority) : key(key), priority(priority) {}
    };

    Min_Heap(int n) {
        heap_array.reserve(n);
        index_heap_array.reserve(n);
        index_heap_array.max_load_factor(0.25);
        size = 0;
    }

    void insert(Node* node) {
        heap_array[size] = node;
        index_heap_array[node->key] = size;
        up_heap(size);
        size++;
    }

    Node* poll() {
        if (size == 0) {
            return nullptr;
        }
        Node* top = heap_array[0];
        size--;
        if (size > 0) {
            heap_array[0] = heap_array[size];
            index_heap_array[heap_array[0]->key] = 0;
            sink_down(0);
        }
        return top;
    }

    void decrease_priority(int key, ll new_priority) {
        if (index_heap_array.find(key) != index_heap_array.end()) {
            int index = index_heap_array[key];
            heap_array[index] = new Node(key, new_priority);
            up_heap(index);
        }
    }

    Node* peek() {
        if (size == 0) {
            return nullptr;
        }
        return heap_array[0];
    }

    bool empty() {
        return size == 0;
    }

private:
    vector<Node*> heap_array;
    unordered_map<int,int> index_heap_array;
    int size;

    void up_heap(int index) {
        int parent_index = parent(index);
        while (parent_index != -1 && heap_array[index]->priority < heap_array[parent_index]->priority) {
            swap(index, parent_index);
            index = parent_index;
            parent_index = parent(index);
        }
    }

    void sink_down(int index) {
        int left_index = 2*index+1, right_index = 2*index+2;
        int min_index = -1;
        if (left_index < size && heap_array[index]->priority > heap_array[left_index]->priority) {
            min_index = left_index;
        }
        if (right_index < size && heap_array[index]->priority > heap_array[right_index]->priority) {
            if (min_index == -1 || heap_array[left_index]->priority > heap_array[right_index]->priority) {
                min_index = right_index;
            }
        }
        if (min_index != -1) {
            swap(index, min_index);
            sink_down(min_index);
        }
    }

    int parent(int index) {
        if (index % 2 != 0) {
            return index/2;
        }
        return index/2 - 1;
    }

    void swap(int index_1, int index_2) {
        Node* element_index_1 = heap_array[index_1];
        heap_array[index_1] = heap_array[index_2];
        heap_array[index_2] = element_index_1;

        index_heap_array[heap_array[index_1]->key] = index_1;
        index_heap_array[heap_array[index_2]->key] = index_2;
    }

};

class Graph {
private:

    struct Edge {
        int start, end, weight;
    };

    int n;
    vector<vector<Edge>> neighbors;

public:
    Graph(int n) {
        this->n = n;
        neighbors.reserve(n);
    }

    void addEdge(int st, int end, int weight) {
        Edge edge = {st,end,weight};
        neighbors[st].push_back(edge);
    }

    vector<ll> djikstra(int src) {
        vector<ll> dist(n);
        vector<bool> visited(n, false);
        dist[0] = 0;
        Min_Heap minHeap(n);
        minHeap.insert(new Min_Heap::Node(0,0));
        for (int i = 1; i < n; ++i) {
            dist[i] = INF;
            minHeap.insert(new Min_Heap::Node(i,INF));
        }
        while (!minHeap.empty()) {
            auto min_node = minHeap.poll();
            int cur_node = min_node->key;
            visited[cur_node] = true;
            for (Edge& edge : neighbors[cur_node]) {
                int neighbor = edge.end;
                if (!visited[neighbor] && dist[neighbor] > dist[cur_node] + edge.weight) {
                    dist[neighbor] = dist[cur_node] + edge.weight;
                    minHeap.decrease_priority(neighbor, dist[neighbor]);
                }
            }
        }
        return dist;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    INF = 1e16;
    int n,m;
    cin >> n >> m;

    Graph graph(n);
    for (int i = 0; i < m; ++i) {
        int a,b,w;
        cin >> a >> b >> w;
        graph.addEdge(a-1,b-1,w);
    }

    vector<ll> shortest_path = graph.djikstra(0);
    printArray(shortest_path, ' ');
    return 0;
}