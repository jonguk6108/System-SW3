#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool descendingComp(const int &a, const int &b){
    if(a > b)
        return true;
    else
        return false;
}


int main(){
    
    int n, order_type;
    vector<int> vec;
    cin >> n;
    cin >> order_type;

    //-----------------------------------------------------------//
    // TODO: Fill your code
    
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    if(order_type == 0) {
        sort(vec.begin(), vec.end());
    }
    else {
        sort(vec.begin(), vec.end(), descendingComp);
    }

    // 3. Vector iterator.
    for(auto it = vec.begin(); it!= vec.end(); it++)
        cout << (*it) << endl;

    //-----------------------------------------------------------//
    
 
}
