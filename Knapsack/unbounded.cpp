#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the unbounded knapsack problem
int unboundedKnapsack(int capacity, const vector<int>& weights, const vector<int>& values) {
    // Create a DP array to store the maximum value for each capacity
    vector<int> dp(capacity + 1, 0);

    // Iterate over each item
    for (int i = 0; i < weights.size(); ++i) {
        // Update the DP array for each capacity
        for (int w = weights[i]; w <= capacity; ++w) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    // The maximum value for the given capacity is in dp[capacity]
    return dp[capacity];
}

int main() {
    // Example items
    vector<int> weights = {1, 3, 4, 5}; // Weights of the items
    vector<int> values = {1, 4, 5, 7};  // Values of the items
    int capacity = 8;                   // Capacity of the knapsack

    int maxValue = unboundedKnapsack(capacity, weights, values);
    cout << "Maximum value in the unbounded knapsack: " << maxValue << endl;

    return 0;
}
