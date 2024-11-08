#include <iostream>
#include <vector>

using namespace std;

int count_subsets_sum(const vector<int>& vect, int sum){

    int n = vect.size();

    vector<int> dp(sum + 1, 0);
    
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= vect[i]; --j) {
            dp[j] += dp[j - vect[i]];
        }
    }
    
    return dp[sum];
}

int main(){
    
    int n,m;
    int sum;
    cin >> n; //numbers of all vectors passed;

    for(int i = 0; i < n; i++){

        cin >> m; //lenght of the first vector
        cin >> sum; //sum to reach
        vector<int> vect(m);

        for(int j = 0; j < m; j++){
            cin >> vect[j];
        }

        cout << count_subsets_sum(vect, sum);
    }

    return 0;
}