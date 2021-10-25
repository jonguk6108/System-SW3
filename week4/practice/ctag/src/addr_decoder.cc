//addr_decoder.cc

#include "addr_decoder.h"
#include <iostream>

using namespace std;

ADDR_INFO get_addr_info (ADDR input_addr){
    
    ADDR virtual_page_number = input_addr / PAGE_SIZE;
    OFFSET offset = (OFFSET)(input_addr % PAGE_SIZE);

    ADDR_INFO result = {virtual_page_number, offset};

    return result;
}

ADDR get_addr (ADDR_INFO info){ return info.virtual_page_number * PAGE_SIZE + (ADDR)info.offset; }

void print_addr_info (ADDR_INFO info) {

    ADDR address = get_addr(info);

    cout << "Address " << address << " Information - Virtual Page Number : " << info.virtual_page_number;
    cout << " Offset : " << info.offset << endl;

    return;
}

void print_addr_info (ADDR addr){

    print_addr_info(get_addr_info(addr));
}
