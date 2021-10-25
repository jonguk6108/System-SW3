#include <iostream>
using namespace std;
// cahnge call by value function to call by ref function 
// do not change if call by reference function is not needed
void get_numbers(int& input1, int& input2);
void swap_values(int& var1, int& var2);
void show_results(int out1, int out2);

int main(){
    int first_num = 0, second_num = 0;
    get_numbers(first_num,second_num);
    swap_values(first_num,second_num);
    show_results(first_num,second_num);
    return 0;
}

void get_numbers(int& input1, int& input2){
    cout<<"Enter two integers: ";
    cin >> input1 >> input2;
}
void swap_values(int& var1, int& var2){
    int temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}
void show_results(int out1, int out2){
    cout<<"In reverse order the numbers are: "
        << out1 << " " << out2 << endl;
}

