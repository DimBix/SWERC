#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lis(vector<int>& arr) {
    if (arr.empty()) return 0;

    vector<int> lci_length;
    lci_length.reserve(arr.size());

    for (int i = 0; i < arr.size(); i++) {
       
        if (lci_length.empty() || lci_length.back() < arr[i]) {
            lci_length.push_back(arr[i]);
        } else {
           
            auto pos = lower_bound(lci_length.begin(), lci_length.end(), arr[i]);
            *pos = arr[i];
        }
    }

    return lci_length.size();
}

int main() {
    int n;
    cin >> n;

    vector<int> vect(n);

    for (int i = 0; i < n; i++) {
        cin >> vect[i];
    }

    cout << lis(vect) << endl;
    return 0;
}
