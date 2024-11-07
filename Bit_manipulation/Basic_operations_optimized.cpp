#include <iostream>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    //odd number
    if(n & 1){
        cout << n << " is odd" <<endl;
    }
    
/*
    /AND
    &
    /OR
    |
    /XOR
    ^
    /NOT
    ~
*/

    //invert all bits
    n = ~(1<<k);

    //setting the k-bit
    n |= (1 << k);

    //clear a bit
    n &= ~(1 << k);

    //module
    n &= ((1 << k) - 1);

    //counting set bits --> Brian Kernighan’s algorithm
    int count = 0;
    while (n){
        n &= (n - 1);
        count += 1;
    }

    //fast division for 2^k (and moltiplication)
    n = (1 >> k);

    //Toggle the k-th bit
    n ^= (1 << k);



    return 0;
}