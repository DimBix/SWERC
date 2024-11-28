#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    // Constructor
    Graph(int vertices) {
        this->vertices = vertices;
        adjList.resize(vertices); // Resize the vector to hold 'vertices' number of lists
    }

    // Function to add an edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add v to u's list
        adjList[v].push_back(u); // Add u to v's list (for undirected graph)
    }

    // Function to display the graph
    void display() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ":";
            for (int neighbor : adjList[i]) {
                cout << " -> " << neighbor;
            }
            cout << endl;
        }
    }

private:
    int vertices; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list
    
    // per grafi pesati uso:
    vector<vector<pair<int, int>>> adjListWeighted;
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display(); // Display the graph

    return 0;
}
