#include <iostream>
using namespace std;
void reverse(int& x, int& y);
// add function definiton
int main(){
    int num;
    int x,y,z;
    cout << "how many numbers wants to present reverse order? : ";
    cin >> num;
    if(num == 2){
        cout << "enter 2 input: ";
        cin >> x >> y;
        reverse(x,y);
        cout << "first: " << x << " second: " << y << endl;
    }else if(num ==3){
        cout << "enter 3 input: ";
        cin >> x >> y >> z;
        // add function call
        cout << "first: " << x << " second: " << y << " third: " << z << endl;
    }else cout<< "invalid" <<endl;
}
void reverse(int& x, int& y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}


/**************************
 *
 * add additinal function
 * to suport 3 number reverse
 * with same name "reverse"
 *
 * ***********************/
