/*
    recursive DFS
*/

#include <iostream>
#include <vector>

using namespace std;

// Directions for moving in the maze (right, down, left, up)
vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// Function to check if a cell is valid (within bounds and not a wall)
bool isValid(int x, int y, const vector<vector<int>>& maze, const vector<vector<bool>>& visited) {
    return (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && 
            maze[x][y] == 0 && !visited[x][y]);
}

// DFS function to find all paths
void dfs(int x, int y, const vector<vector<int>>& maze, vector<vector<bool>>& visited, 
          vector<pair<int, int>>& path, vector<vector<pair<int, int>>>& allPaths) {
    
    // If we reach the destination, store the path
    if (x == maze.size() - 1 && y == maze[0].size() - 1) {
        allPaths.push_back(path);
        return;
    }

    // Mark the cell as visited
    visited[x][y] = true;
    path.push_back({x, y});

    // Explore all possible directions
    for (const auto& dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;

        if (isValid(newX, newY, maze, visited)) {
            dfs(newX, newY, maze, visited, path, allPaths);
        }
    }

    // Backtrack: unmark the cell and remove it from the path
    visited[x][y] = false;
    path.pop_back();
}

int main() {
    // Initialize the maze (0 = path, 1 = wall)
    vector<vector<int>> maze = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0}
    };

    vector<vector<pair<int, int>>> allPaths; // To store all paths
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<pair<int, int>> path; // Current path

    // Start DFS from the top-left corner (0, 0)
    dfs(0, 0, maze, visited, path, allPaths);

    // Print all found paths
    cout << "All paths from (0, 0) to (" << maze.size() - 1 << ", " << maze[0].size() - 1 << "): " << allPaths.size() << endl;
    for (const auto& p : allPaths) {
        for (const auto& cell : p) {
            cout << "(" << cell.first << ", " << cell.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
