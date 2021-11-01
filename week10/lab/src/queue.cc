/* *************************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : queue.cc
 * - File Type : c++ source code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is queue structure code for SSE2034-41(SKKU, 2021) class Lab 10.
 *                 Do not distribute this code without permission.
 * *************************************************************************************************************/

#include "queue.h"

namespace Queue {

    structure::structure() {
        front_ptr = NULL;
        back_ptr = NULL;
        size = 0;
    }

    structure::~structure() {
        node *next_node = front_prt;
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
            back_ptr = new_node;
            front_prt = new_node;
        } 
        else {
            node *new_node = new node;
            new_node->data = data;
            new_node->next = NULL;

            back_ptr->next = new_node;
            back_ptr = new_node;
        }

        size++;
    }

    int structure::front() {
        return front_ptr->data;
    }

    int structure::pop() {
        int ret = front_ptr->data;
        node *delete_node = front_ptr;
        front_ptr = front_ptr->next;
        size--;

        delete delete_node;

        return ret;
    }

    size_t structure::get_size() {return size;}
    bool structure::empty() {return size == 0;}
}
