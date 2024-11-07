#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void generating_subsets(const vector<int>& vect){
    int size = vect.size();
    int n_sub = (1 << size);

    for(int i = 0; i < n_sub; i++){
        vector<int> subsets;
        
        for(int j = 0; j < size; j++){
            if(i & (1 << j)){
                subsets.push_back(vect[j]);
            }
        }

       for (int num : subsets) {
            cout << num << ' ';
        }
        cout << endl;
    }
}

int main(){

    int n,m;
    cin >> n; //numbers of all vectors passed;

    for(int i = 0; i < n; i++){

        cin >> m; //lenght of the first vector
        vector<int> vect(m);

        for(int j = 0; j < m; j++){
            cin >> vect[j];
        }

        generating_subsets(vect);
    }

    return 0;
}