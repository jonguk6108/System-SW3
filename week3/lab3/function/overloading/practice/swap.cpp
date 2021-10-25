#include <iostream>
using namespace std;
void get_numbers(int& input1, int& input2);
void get_numbers(double& input1, double& input2);
void swap_values(int& var1, int& var2);
void swap_values(double& var1, double& var2);
void show_results(int out1, int out2);
void show_results(double out1, double out2);
// add newly added function definition

int main(){
    int first_num = 0, second_num = 0;
    double first = 0, second = 0;
    cout<<"integer swap" <<endl;
    get_numbers(first_num,second_num);
    swap_values(first_num,second_num);
    show_results(first_num,second_num);
    cout<<"double swap" <<endl;
    get_numbers(first,second);
    swap_values(first,second);
    show_results(first,second);
    return 0;
}

void get_numbers(int& input1, int& input2){
    cout<<"Enter two integers: ";
    cin >> input1 >> input2;
}
void get_numbers(double& input1, double& input2){
    cout<<"Enter two integers: ";
    cin >> input1 >> input2;
}

void swap_values(int& var1, int& var2){
    int temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}
void swap_values(double& var1, double& var2){
    double temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}
void show_results(int out1, int out2){
    cout<<"In reverse order the numbers are: "
        << out1 << " " << out2 << endl;
}
void show_results(double out1, double out2){
    cout<<"In reverse order the numbers are: "
        << out1 << " " << out2 << endl;
}
/***************************************************
 *
 * add new function to support double type operation
 * the name of function is same as before
 * ("get_numbers, swap_values, show_results")
 *
 * ************************************************/
