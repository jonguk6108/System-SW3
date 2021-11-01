/* *************************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : stack.cc
 * - File Type : c++ source code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is stack structure code for SSE2034-41(SKKU, 2021) class Lab 10.
 *                 Do not distribute this code without permission.
 * *************************************************************************************************************/

#include "stack.h"

namespace Stack {

    structure::structure() {
        top_ptr = NULL;
        size = 0;
    }

    structure::~structure() {
        node *next_node = top_ptr;
        while(next_node != NULL) {
            node *delete_node = next_node;
            next_node = next_node->next;

            delete delete_node;
        }
    }

    void structure::push(int data) {
        if(size == 0) {
            node *new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            top_ptr = new_node;
        }
        else {
            node *new_node = new node;
            new_node->data = data;
            new_node->next = top_ptr;

            top_ptr = new_node;
        }
        size++;
    }

    int structure::top() {
        return top_ptr->data;
    }

    int structure::pop() {
        int ret = top_ptr->data;
        node *delete_node = top_ptr;
        top_ptr = top_ptr->next;
        size--;

        delete delete_node;

        return ret;
    }

    size_t structure::get_size() {return size;}

    bool structure::empty() {return size == 0;}


}
