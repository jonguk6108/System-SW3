/* *************************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : queue.cc
 * - File Type : c++ source code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is queue structure code for SSE2034-41(SKKU, 2021) class Practice10.
 *                 Do not distribute this code without permission.
 * *************************************************************************************************************/

#include "queue.h"

namespace Queue {

    structure::structure() {
        //TODO : Constructor
    }

    structure::~structure() {
        //TODO : Destructor, Must free dynamic mallocs
    }

    void structure::push(int data) {
        //TODO : Push data to queue
    }

    int structure::front() {
        //TODO : Return front value
    }

    int structure::pop() {
        //TODO : Return front value and remove front value
    }

    size_t structure::get_size() {return size;}
    bool structure::empty() {return size == 0;}
}
