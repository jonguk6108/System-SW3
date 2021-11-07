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
        std::vector<uint8_t> new_symbols = (*lhs).get_symbols();
        std::vector<uint8_t> rhs_symbols = (*rhs).get_symbols();

        for(size_t i = 0; i < rhs_symbols.size(); i++)
            new_symbols.push_back(rhs_symbols.at(i));

        node *new_node = new node(new_symbols, (*lhs).get_count() + (*rhs).get_count(), lhs, rhs);

        return new_node;
    }

    bool is_smaller(node *lhs, node *rhs) {
        if( (*lhs).get_count() < (*rhs).get_count() ) return true;
        else if( (*lhs).get_count() > (*rhs).get_count() ) return false;

        std::vector<uint8_t> lhs_symbols = (*lhs).get_symbols();
        std::vector<uint8_t> rhs_symbols = (*rhs).get_symbols();
        
        if( lhs_symbols.size() < rhs_symbols.size() ) return true;
        else if( lhs_symbols.size() > rhs_symbols.size() ) return false;

        uint8_t lhs_symbol = lhs_symbols.at(0);
        for(size_t i = 0; i < lhs_symbols.size(); i++)
            if(lhs_symbol > lhs_symbols.at(i))
                lhs_symbol = lhs_symbols.at(i);

        uint8_t rhs_symbol = rhs_symbols.at(0);
        for(size_t i = 0; i < rhs_symbols.size(); i++)
            if(rhs_symbol > rhs_symbols.at(i))
                rhs_symbol = rhs_symbols.at(i);

        if(lhs_symbol < rhs_symbol) return true;
        return false;
    }

    PriorityNodeQueue::PriorityNodeQueue()
    {
        nodes.clear();
    }

    void PriorityNodeQueue::push(node *node_ptr) {
        nodes.push_back(node_ptr);
        sort();
    }

    node *PriorityNodeQueue::front() {
        return nodes.at(0);
    }

    node *PriorityNodeQueue::pop() {
        node * ret = nodes.at(0);

        nodes.erase(nodes.begin());
        return ret;
    }

    PriorityNodeQueue::~PriorityNodeQueue() {
        while(1) {
            if(nodes.size() == 0)
                return;
            delete [] nodes.at(nodes.size() - 1);
        }
    }

    size_t PriorityNodeQueue::size() {return nodes.size();}

    bool PriorityNodeQueue::empty(){return (nodes.size()==0);}

    void PriorityNodeQueue::sort() {
        for(size_t i = 0; i < nodes.size(); i++) {
            for(size_t j = 0; j < nodes.size()-i-1; j++) {
                if(is_smaller(nodes.at(j), nodes.at(j+1)) == 0) {
                    node * temp_node = nodes.at(j);
                    nodes.at(j) = nodes.at(j+1);
                    nodes.at(j+1) = temp_node;
                }
            }
        }
    }

    tree::tree() {
        symbol_table.clear();
        encoding_table.clear();
        priority_node_queue = NULL;
    }

    tree::tree(std::vector<uint8_t> symbols, std::vector<size_t> count) {
        symbol_table = symbols;
        encoding_table.clear();
        PriorityNodeQueue * node_queue = new PriorityNodeQueue;
        priority_node_queue = node_queue;

        for(size_t i = 0; i < symbol_table.size(); i++) {
            std::vector<uint8_t> new_symbol;
            new_symbol.push_back(symbol_table.at(i));
            node *push_node = new node(new_symbol, count.at(i));
            priority_node_queue->push(push_node);
        }

        while(1) {
            if(priority_node_queue->size() == 1)
                break;
            node *second_node = priority_node_queue->pop();
            node *first_node = priority_node_queue->pop();
            node *push_node = merge_node(first_node, second_node);
            priority_node_queue->push(push_node);
        }

        root = priority_node_queue->pop();

        for(size_t i = 0; i < symbol_table.size()-1; i++)
            for(size_t j = i + 1; j < symbol_table.size(); j++)
                if(symbol_table.at(i) > symbol_table.at(j)) {
                    uint8_t temp = symbol_table.at(i);
                    symbol_table[i] = symbol_table[j];
                    symbol_table[j] = temp;
                }

        for(size_t i = 0; i < symbol_table.size(); i++) {
            uint8_t current_symbol = symbol_table.at(i);
            std::string ret_str = "";
            node *current_node = root;
            node *next_node;
            while(1) {
                if(current_node->get_left() == NULL && current_node->get_right() == NULL)
                    break;
                
                next_node = current_node->get_left();
                std::vector<uint8_t> tmp_symbol = next_node->get_symbols();\
                int next = 1;
                for(size_t j = 0; j < tmp_symbol.size(); j++)
                    if(tmp_symbol.at(j) == current_symbol)
                        next = 0;
                if(next == 1) {
                    ret_str += '1';
                    current_node = current_node->get_right();
                }
                else {
                    ret_str += '0';
                    current_node = next_node;
                }
            }
            encoding_table.push_back(ret_str);
        }
    }

    tree::~tree() {
        delete [] priority_node_queue;
    }

    std::string tree::encode_symbols(std::vector<uint8_t> symbols) const {
        std::string ret_str = "";

        for(size_t i = 0; i < symbols.size(); i++) {
            int i_symbol = 0;
            for(size_t j = 0; j < symbol_table.size(); j++)
                if(symbol_table.at(j) == symbols.at(i))
                    i_symbol = j;
            ret_str += encoding_table.at(i_symbol);
        }
        return ret_str;
    }

    std::vector<uint8_t> tree::decode_symbols(std::string encode_symbols) {
        std::vector<uint8_t> ret;
        
        size_t i = 0;
        while(1) {
            if(i >= encode_symbols.size())
                break;

            node *current_node = root;
            while(1) {
                if(current_node->get_left() == NULL && current_node->get_right() == NULL)
                    break;
                if(encode_symbols[i] == '0')
                    current_node = current_node->get_left();
                else
                    current_node = current_node->get_right();
                i++;
            }
            ret.push_back(current_node->get_symbols().at(0));
        }
        return ret;
    }

    tree *get_tree(std::vector <uint8_t> original_data) {
        int check[256] = {0, };
        std::vector<uint8_t> put_symbols;
        std::vector<size_t> count;

        int temp_count;

        for(size_t i = 0; i < original_data.size(); i++) {
            if(check[original_data.at(i)] == 1)
                continue;
            check[original_data.at(i)] = 1;

            temp_count = 1;
            for(size_t j = i + 1; j < original_data.size(); j++)
                if(original_data.at(j) == original_data.at(i)) {
                    temp_count++;
                    check[original_data.at(i)] = 1;
                }
            put_symbols.push_back(original_data.at(i));
            count.push_back(temp_count);
        }

        tree *ret_tree = new tree(put_symbols, count);
        return ret_tree;
    }
}
