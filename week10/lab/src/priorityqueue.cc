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
        datas.clear();
    }

    void structure::push(int data) {
        datas.push_back(data);
        sort();
    }

    int structure::front() {
        return datas.at(0);
    }

    int structure::pop() {
        int ret = datas.at(0);

        datas.erase(datas.begin());
        return ret;
    }

    size_t structure::get_size() {return datas.size();}
    bool structure::empty() {return datas.size() == 0;}

    void structure::sort() {
        for(size_t i = 0; i < datas.size(); i++) {
            for(size_t j = 0; j < datas.size()-i-1; j++) {
                if(datas.at(j+1) > datas.at(j)) {
                    int temp = datas.at(j);
                    datas.at(j) = datas.at(j+1);
                    datas.at(j+1) = temp;
                }
            }
        }
    }
}
