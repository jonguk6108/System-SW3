/* *************************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : huffman.h
 * - File Type : c++ header code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is provided huffman header code for SSE2034-41(SKKU, 2021) class HW 10.
 *                 Do not distribute this code without permission.
 * *************************************************************************************************************/


#ifndef HUFFMAN_H
#define HUFFMAN_H

//Do Not Include Other libraries
#include <vector>
#include <string>
#include "data.h"

const uint8_t MAX_VALUE_LIMIT = 255;

/*******************************************************************************************
 * 1. You can add andy function, variable in namespaces
 * 2. Do not remove pre-defined funcition or variables.
 * *****************************************************************************************/
namespace Huffman {

    class node {
        private:
        std::vector <uint8_t> symbols;
        size_t count;
        node *left;
        node *right;

        friend class tree;
        friend class PriorityNodeQueue;

        public:
        node(std::vector<uint8_t> symbols_, size_t count_);
        node(std::vector<uint8_t> symbols_, size_t count_, node *left_, node *right_);
        ~node();

        std::vector<uint8_t> get_symbols() const;
        size_t get_count() const;
        node *get_left() const;
        node *get_right() const;
    };

    bool is_smaller(node *lhs, node *rhs);

    node *merge_node(node *lhs, node *rhs);

    class PriorityNodeQueue {
        private:
        std::vector <node *> nodes;

        void sort();

        public:
        PriorityNodeQueue();
        ~PriorityNodeQueue();

        void push(node *node_ptr);
        node *front();
        node *pop();
        size_t size();
        bool empty();
    };

    class tree {
        private:
        node *root = NULL;
        std::vector <uint8_t> symbol_table;
        std::vector <std::string> encoding_table;
        PriorityNodeQueue *priority_node_queue = NULL;

        public:
        tree();
        tree(std::vector<uint8_t> symbols, std::vector <size_t> count);
        ~tree();

        std::string encode_symbols(std::vector <uint8_t> symbols) const;
        std::vector <uint8_t> decode_symbols(std::string encode_symbols);

        std::vector<uint8_t> get_symbol_table() {return symbol_table;}
        std::vector<std::string> get_encoding_table() {return encoding_table;}
    };

    tree *get_tree(std::vector<uint8_t> original_data);

}

#endif
