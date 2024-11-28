#include <iostream>
#include <vector>
#include <unordered_set>

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

    // DFS function
    void dfs(int start) {
        unordered_set<int> visited; // Set to keep track of visited nodes
        dfsUtil(start, visited); // Call the utility function
    }

private:
    int vertices; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

    // Utility function for DFS
    void dfsUtil(int vertex, unordered_set<int>& visited) {
        visited.insert(vertex); // Mark the vertex as visited
        cout << vertex << " "; // Process the vertex (e.g., print it)

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adjList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsUtil(neighbor, visited); // Recur for unvisited neighbors
            }
        }
    }
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

    cout << "DFS starting from vertex 0:" << endl;
    g.dfs(0); // Start DFS from vertex 0

    return 0;
}
