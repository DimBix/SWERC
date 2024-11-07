/*
    This version is optimized for returning only the lenght of the subsequence
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int lcs(const string &A, const string &B) {
    int m = A.length();
    int n = B.length();


    if (m > n) {
        return lcs(B, A);
    }

    vector<int> previous(m + 1, 0);
    vector<int> current(m + 1, 0);


    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            if (A[i - 1] == B[j - 1]) {
                current[i] = previous[i - 1] + 1;
            } else {
                current[i] = max(previous[i], current[i - 1]);
            }
        }
        previous = current;
    }

    return previous[m];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    while(n--){
        string s1, s2;
        cin >> s1 >> s2;

        cout << lcs(s1,s2) << endl;
        cout.flush();
    }
    
    return 0;
}