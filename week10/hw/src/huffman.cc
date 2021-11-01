/* *************************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : huffman.cc
 * - File Type : c++ header code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is provided huffman code for SSE2034-41(SKKU, 2021) class HW 10.
 *                 Do not distribute this code without permission.
 * *************************************************************************************************************/

#include "huffman.h"
#include <cassert>
#include <algorithm>

namespace Huffman{

    node::node(std::vector<uint8_t> symbols_, size_t count_)
    {
        symbols = symbols_;
        count = count_;
        left = NULL;
        right = NULL;
    }

    node::node(std::vector<uint8_t> symbols_, size_t count_, node *left_, node *right_)
    {
        symbols = symbols_;
        count = count_;
        left = left_;
        right = right_;
    }

    node::~node()
    {
        if (left != NULL) delete left;
        if (right != NULL) delete right;
    }

    std::vector<uint8_t> node::get_symbols() const {return symbols;}

    size_t node::get_count() const {return count;}

    node *node::get_left() const {return left;}
    node *node::get_right() const {return right;}

    node *merge_node(node *lhs, node *rhs){
        //TODO : 
    }

    bool is_smaller(node *lhs, node *rhs) {
        //TODO : 
    }

    PriorityNodeQueue::PriorityNodeQueue()
    {
        //TODO : 
    }

    void PriorityNodeQueue::push(node *node_ptr) {
        //TODO : 
    }

    node *PriorityNodeQueue::front() {
        //TODO : 
    }

    node *PriorityNodeQueue::pop() {
        //TODO :
    }

    PriorityNodeQueue::~PriorityNodeQueue() {
        //TODO :
    }

    size_t PriorityNodeQueue::size() {return nodes.size();}

    bool PriorityNodeQueue::empty(){return (nodes.size()==0);}

    void PriorityNodeQueue::sort() {
        //TODO : 
    }

    tree::tree() {
        //TODO
    }

    tree::tree(std::vector<uint8_t> symbols, std::vector<size_t> count) {
        //TODO
    }

    tree::~tree() {
        //TODO
    }

    std::string tree::encode_symbols(std::vector<uint8_t> symbols) const {
        //TODO
    }

    std::vector<uint8_t> tree::decode_symbols(std::string encode_symbols) {
        //TODO
    }

    tree *get_tree(std::vector <uint8_t> original_data) {
        //TODO
    }
}
