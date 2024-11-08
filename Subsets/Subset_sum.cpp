/*
    Uso una dp, le colonne corrispondono alla somma da 0 a sum,
    le righe invece sono gli elementi del vettore.
    Itero e controllo se l'elemento selezionato del  vettore è maggiore della somma, in quel caso prendo il risultato precedente.
    (quindi mi sposto indietro nella colonna e se quella somma j era già stata fatta dico semplicemente che è possibile farla)
    Se invece è minore della somma j, posso escluderlo oppure prenderlo, nel secondo caso, andrò a inserire il risultato dalla cella
    dp[i-1][j - vect[i-1]]... ossia j-vect[i-1] mi da la somma rimanente tolto l'elemento che ho deciso di prendere.
    Ora quindi punto alla cella con la somma j-vect[i-1] se è fattibile significa che vect[i-1] può essere aggiunto con risultato positivo altrimenti no


    vector<vector<bool>> dp(n+1, vector<bool>(sum + 1, false));

    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(vect[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j - vect[i-1]];
            }
        }
    }




*/


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool subset_sum(const vector<int>& vect, int sum){

    vector<bool> dp(sum+1, false);
    dp[0] = true;

    for(int j = 0; j <= vect.size(); j++){
        for(int i = sum; i >= vect[j]; i--){
            dp[i] = dp[i] || dp[i - vect[j]];
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

        cout << subset_sum(vect, sum);
    }

    return 0;
}