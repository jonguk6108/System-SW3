
/* *************************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : priorityqueue.h
 * - File Type : c++ header code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is provided priority queue structure header code for SSE2034-41(SKKU, 2021)
 *                 class Lab 10. Do not modify this code! Do not distribute this code without permission.
 * *************************************************************************************************************/

#ifndef PriorityQueue_H
#define PriorityQueue_H

#include <vector>

namespace PriorityQueue {

    class structure {
        private:
        std::vector <int> datas;
        
        void sort();

        public:
        structure();

        void push(int data);
        int front();
        int pop();

        size_t get_size();
        bool empty();
    };
}

#endif
