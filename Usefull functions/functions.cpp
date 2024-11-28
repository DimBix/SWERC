#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main(){
    vector<int> vect(10);
    int value, position;

    auto it = vect.begin();

    advance(it, position);

    vect.erase(it);

    vect.push_back(value);

    vect.pop_back();

    vect.back();

    vect.front();

    vect.assign(position, value);

    find(vect.begin(), vect.end(), value);

    //------------------------------------

    deque<int> dq;

    // permette tutti i push e pop in tempo costante (sia front che back)
    //oppure usa list...

    list<int> lst;


    return 0;
}