#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Item{
    int value;
    int weigth;
    double ratio;
};

bool compare(Item a, Item b){
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int capacity, vector<Item>& items){
    
    double max_value = 0.0;

    sort(items.begin(), items.end(), compare);

    for(const auto& item: items){
        
        if(capacity <= 0){
            break;
        }

        if(item.weigth <= capacity){
            max_value += item.value;
            capacity -= item.weigth;
        }else{
            max_value += capacity * item.ratio;
            capacity = 0;
        }
    }

    return max_value;
}

int main(){
    // Example items
    vector<Item> items = {
        {60, 10, 6.0}, // value, weight, value/weight ratio
        {100, 20, 5.0},
        {120, 30, 4.0}
    };

    int capacity = 50;

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}