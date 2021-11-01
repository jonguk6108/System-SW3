/* *************************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : stack.h
 * - File Type : c++ header code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is provided stack structure header code for SSE2034-41(SKKU, 2021) class Lab 10.
 *                 Do not modify this code! Do not distribute this code without permission.
 * *************************************************************************************************************/
#ifndef STACK_H
#define STACK_H

#include "common.h"
#include <cstdlib>

namespace Stack {

    class structure {
        private:
        node *top_ptr;
        size_t size;

        public:
        structure();
        ~structure();

        void push(int data);
        int top();
        int pop();

        size_t get_size();
        bool empty();
    };
    
}

#endif
