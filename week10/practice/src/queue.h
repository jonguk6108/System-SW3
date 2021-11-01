/* *************************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : queue.h
 * - File Type : c++ header code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is provided queue structure header code for SSE2034-41(SKKU, 2021) class Practice10.
 *                 Do not modify this code! Do not distribute this code without permission.
 * *************************************************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"
#include <cstdlib>

namespace Queue {

    class structure {
        private:
        node *front_ptr;
        node *back_ptr;
        size_t size;

        public:
        structure();
        ~structure();

        void push(int data);
        int front();
        int pop();

        size_t get_size();
        bool empty();
        
    };
}

#endif
