#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Function to perform BFS on the graph
void bfs(const vector<vector<int>>& graph, int start) {
    unordered_set<int> visited; // Set to keep track of visited nodes
    queue<int> q; // Queue for BFS

    q.push(start); // Enqueue the starting node
    visited.insert(start); // Mark the starting node as visited

    while (!q.empty()) {
        int vertex = q.front(); // Get the front vertex
        q.pop(); // Dequeue the vertex

        cout << vertex << " "; // Process the vertex (e.g., print it)

        // Enqueue all unvisited neighbors
        for (int neighbor : graph[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor); // Enqueue the neighbor
                visited.insert(neighbor); // Mark it as visited
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    // Graph: 0 -- 1 -- 2
    //         |    |
    //         3 -- 4
    vector<vector<int>> graph = {
        {1, 3},    // Neighbors of vertex 0
        {0, 2, 4}, // Neighbors of vertex 1
        {1},       // Neighbors of vertex 2
        {0, 4},    // Neighbors of vertex 3
        {1, 3}     // Neighbors of vertex 4
    };

    cout << "BFS starting from vertex 0:" << endl;
    bfs(graph, 0); // Start BFS from vertex 0

    return 0;
}
