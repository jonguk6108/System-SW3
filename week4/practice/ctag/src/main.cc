//main.cc

#include <iostream>
#include "addr_decoder.h"
#include <string>

#define STUDENT_ID "2021312034"

using namespace std;

int main (int argc, char *argv[]) {

    //Argument Check
    if (argc != 2) {
        cout << "Argument Error!" << endl;
        cout << "./addr_decoder [address]" << endl;
        cout << "Exit The Program!" << endl;
        return 1;
    }

    ADDR input_addr = stoull(argv[1]);

    ADDR_INFO decode_result = get_addr_info(input_addr);
    ADDR restore_addr = get_addr(decode_result);

    cout << "My Student ID is " << STUDENT_ID << endl;
    cout << "Input Address : " << input_addr << endl;
    print_addr_info(decode_result);
    cout << "Restore Address : " << restore_addr << endl;

    return 0;

}
