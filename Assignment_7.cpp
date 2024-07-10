#include <iostream>
#include <algorithm>
#define SIZE 20
#define INFINITY 99
using namespace std;

class MST {
private:
    int G[SIZE][SIZE], nodes;
    struct Edge {
        int src, dest, weight;
    };
    Edge edges[SIZE * SIZE]; // Assuming maximum possible edges are SIZE * SIZE
public:
    MST();
    void Prim();
    void Kruskal();
    void get_data();
};

MST::MST() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            G[i][j] = 0;
        }
    }
}

void MST::Prim() {
    int select[SIZE], i, j, k;
    int min_dist, v1, v2, total = 0;
    cout << "\nThe minimum spanning tree (Prim's algorithm)" << endl;
    for (int i = 0; i < nodes; i++) {
        select[i] = 0;
        select[0] = 1;
    }
    for (int k = 0; k < nodes - 1; k++) {
        min_dist = INFINITY;
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes - 1; j++) {
                if (G[i][j] && ((select[i] && !select[j]) || (!select[i] && select[j]))) {
                    if (G[i][j] < min_dist) {
                        min_dist = G[i][j];
                        v1 = i;
                        v2 = j;
                    }
                }
            }
        }
        cout << "Edge " << v1 << " " << v2 << " and Weight = " << min_dist << "\n";
        select[v1] = select[v2] = 1;
        total = total + min_dist;
    }
    cout << "\nTotal path length is " << total << endl;
}

void MST::Kruskal() {
    sort(edges, edges + nodes * nodes, [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    int parent[SIZE];
    for (int i = 0; i < nodes; i++) {
        parent[i] = i;
    }

    int total = 0;
    cout << "\nThe minimum spanning tree (Kruskal's algorithm)" << endl;
    for (int i = 0; i < nodes * nodes; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        int parentSrc = parent[src];
        int parentDest = parent[dest];

        if (parentSrc != parentDest) {
            cout << "Edge " << src << " " << dest << " and Weight = " << weight << "\n";
            total += weight;
            // Merge the two sets
            for (int j = 0; j < nodes; j++) {
                if (parent[j] == parentDest) {
                    parent[j] = parentSrc;
                }
            }
        }
    }
    cout << "\nTotal path length is " << total << endl;
}

void MST::get_data() {
    int v1, v2, length, n;
    cout << "\nEnter the total number of nodes in the graph: ";
    cin >> nodes;
    cout << "\nEnter the total number of edges in the graph: ";
    cin >> n;
    cout << "\nEnter the edge and weight of the graph: ";
    for (int i = 0; i < n; i++) {
        cout << "\nEnter the edge in the form of v1, v2 (e.g., if there is an edge between 0 and 1 then write 0 1): " << endl;
        cin >> v1 >> v2;
        cout << "\nEnter corresponding weight: " << endl;
        cin >> length;
        G[v1][v2] = G[v2][v1] = length;
        edges[i].src = v1;
        edges[i].dest = v2;
        edges[i].weight = length;
    }
}

int main() {
    MST obj;
    cout << "\nPrim's Algorithm\n";
    obj.get_data();
    cout << " " << endl;
    obj.Prim();

    // Call Kruskal's algorithm
    cout << "\nKruskal's Algorithm\n";
    obj.get_data();
    cout << " " << endl;
    obj.Kruskal();

    return 0;
}
