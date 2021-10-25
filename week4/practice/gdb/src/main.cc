#include <iostream>
#include "my_sort.h"

using namespace std;

int main (int argc, char *argv[]){

    int array[10];

    if (argc != 11){
        cout << "Argument Error! - Enter 10 digits" << endl;
        return 0;
    } else {

        for (int i=0; i<10; i++) {

            array[i] = atoi(argv[i+1]);

        }
    }

    cout << "Original Array : ";
    for (int i=0; i<10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    quick_sort(array, 10);

    cout << "Sorted Array : ";
    for (int i=0; i<10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
