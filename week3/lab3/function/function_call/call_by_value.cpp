#include <iostream>
using namespace std;
void callbyvalue(int x, int y);
int main(){
    int x,y;
    cout << "enter 2 numbers: ";
    cin >> x >> y;
    callbyvalue(x,y);
    cout << "first: " << x << " second: " << y << endl;
}
void callbyvalue(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}
