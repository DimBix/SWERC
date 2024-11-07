#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lps(const string& v) {
    int size = v.size();
    if (size == 0) return 0;

    string reversedString = v;
    reverse(reversedString.begin(), reversedString.end());

    //we perform lcs optimized

    vector<int> current(size + 1, 0);
    vector<int> previous(size + 1, 0);

    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            if (reversedString[j - 1] == v[i - 1]) {
                current[j] = previous[j - 1] + 1;
            } else {
                current[j] = max(current[j - 1], previous[j]);
            }
        }
        previous = current;
    }
    return current[size];
}

int main() {
    int n;
    cin >> n;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << lps(s) << endl;
    }

    return 0;
}
