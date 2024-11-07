#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_lcs(const string &s1, const string &s2){

    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1,0));

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int index = dp[m][n];
    string lcs_str(index, ' ');
    int i = m, j = n;
    
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs_str[index - 1] = s1[i-1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    cout << lcs_str << endl;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    while(n--){
        string s1, s2;
        cin >> s1 >> s2;

        print_lcs(s1,s2);
        cout.flush();
    }
    return 0;
}