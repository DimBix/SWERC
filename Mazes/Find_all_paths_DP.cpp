#include <iostream>
#include <vector>

using namespace std;

int countPathsDP(const vector<vector<int>>& maze) {
    int n = maze.size();
    int m = maze[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    if (maze[0][0] == 0) {
        dp[0][0] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 1) {
                continue;
            }
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0}
    };

    int totalPaths = countPathsDP(maze);
    cout << "Total number of paths from (0, 0) to (" << maze.size() - 1 << ", " << maze[0].size() - 1 << "): " << totalPaths << endl;

    return 0;
}
