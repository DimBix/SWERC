#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int B; // Budget
    int N; // Number of recipes
    cin >> B >> N;

    unordered_map<string, pair<int, int>> dish_info; // dish -> (min_cost, max_prestige)
    dish_info["pizza_base"] = {0, 0}; // Base dish has cost 0 and prestige 0

    for (int i = 0; i < N; ++i) {
        string derived, base, ingredient;
        int added_cost, added_prestige;
        cin >> derived >> base >> ingredient >> added_cost >> added_prestige;

        // Get the base dish's cost and prestige
        int base_cost = dish_info[base].first;
        int base_prestige = dish_info[base].second;

        // Calculate total cost and prestige for the derived dish
        int total_cost = base_cost + added_cost;
        int total_prestige = base_prestige + added_prestige;

        // Update the dish_info for the derived dish
        auto& current_info = dish_info[derived];
        if (total_cost < current_info.first || 
            (total_cost == current_info.first && total_prestige > current_info.second)) {
            current_info = {total_cost, total_prestige};
        }
    }

    // Prepare a list of (cost, prestige) pairs for the dishes
    vector<pair<int, int>> dishes;
    for (const auto& entry : dish_info) {
        if (entry.second.first != numeric_limits<int>::max()) {
            dishes.push_back(entry.second);
        }
    }

    // Dynamic programming to solve the knapsack problem
    vector<int> dp(B + 1, 0);

    for (const auto& dish : dishes) {
        int cost = dish.first;
        int prestige = dish.second;

        for (int b = B; b >= cost; --b) {
            dp[b] = max(dp[b], dp[b - cost] + prestige);
        }
    }

    // Find the maximum prestige and the corresponding minimum cost
    int max_prestige = *max_element(dp.begin(), dp.end());
    int min_cost = 0;
    for (int b = 0; b <= B; ++b) {
        if (dp[b] == max_prestige) {
            min_cost = b;
            break;
        }
    }

    cout << max_prestige << endl;
    cout << min_cost << endl;

    return 0;
}
