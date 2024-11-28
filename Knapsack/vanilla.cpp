/*
Come sempre è ottimmizzabile nello spazio...
*/

#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values){

    int n = weights.size();

    vector<vector<int>> dp(n+1, vector<int>(capacity + 1, 0));

    for(int i = 1; i <= n; i++){

        for(int j = 0; j <= capacity; j++){

            if(weights[i - 1] <= j){
                dp[i][j] = max(values[i-1] + dp[i-1][j - weights[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][capacity];
}


int main(){
    //input handling

    // Example items
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 5;

    int maxValue = knapsack(capacity, weights, values);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
