/* *************************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : priorityqueue.cc
 * - File Type : c++ source code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is priority queue structure code for SSE2034-41(SKKU, 2021) class Lab 10.
 *                 Do not distribute this code without permission.
 * *************************************************************************************************************/

#include "priorityqueue.h"

namespace PriorityQueue {

    structure::structure() {
        //TODO : Constructor
    }

    void structure::push(int data) {
        //TODO : Push data to priority queue
    }

    int structure::front() {
        //TODO : retrun front value
    }

    int structure::pop() {
        //TODO : return front value and remove front
    }

    size_t structure::get_size() {return datas.size();}
    bool structure::empty() {return datas.size() == 0;}

    void structure::sort() {
        //TODO : Sort Data / Greater one is pop() first!
    }
}
