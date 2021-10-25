#include <iostream>

using namespace std;

int main(){
    
    //-----------------------------------------------------------//
    // TODO: Fill your code

    int a[42] = {0,}, tmp;
    int i;
    for(i = 0; i < 10; i++) {
        cin >> tmp;
        a[tmp%42]++;
    }
    int sol = 0;
    for(i = 0; i < 42; i++) {
        if(a[i] != 0) sol++;
    }
    cout << sol;

    //-----------------------------------------------------------//
}
