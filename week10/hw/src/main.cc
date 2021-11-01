/* ***************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : main.cc
 * - File Type : c++ source code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is provided main function code for SSE2034-41(SKKU, 2021) class HW 10.
 *                 Do not modify this code! Do not distribute this code without permission.
 * **************************************************************************************************/

#include <vector>
#include <string>
#include <iostream>

#include "data.h"
#include "huffman.h"

int main(int argc, char *argv[])
{

    std::string file_name;

    if (argc != 2) {
        std::cout << "Argument Error!" << std::endl;
        return 0;
    } else {
        file_name = argv[1];
    }

    std::cout << "Reading " << file_name << " File Data ..." << std::endl;
    std::vector<uint8_t> original_data = DATA::get_data(file_name);

    std::cout << "Generating Huffman Tree ..." << std::endl;
    Huffman::tree *huffman_tree = Huffman::get_tree(original_data);

    std::cout << "Compressing data ..." << std::endl;
    std::string comprssed_bitstream = huffman_tree->encode_symbols(original_data);
    
    std::cout << "Generating Huffman Table ..." << std::endl;
    std::vector<uint8_t> unique_symbols = huffman_tree->get_symbol_table();
    std::vector<std::string> encoding_table = huffman_tree->get_encoding_table();
   
    std::cout << "Decoding test ..." << std::endl;
    std::string decoding_test = huffman_tree->encode_symbols(unique_symbols);
    std::vector<uint8_t> decode_data = huffman_tree->decode_symbols(decoding_test);

    std::cout << "Huffman Table" << std::endl;
    for (size_t i=0; i<unique_symbols.size(); i++) {
        std::cout << (unsigned)unique_symbols.at(i) << " Convert To " << encoding_table.at(i) << "." << std::endl;
    }

    bool decode_success = true;
    
    for (size_t i=0; i<unique_symbols.size(); i++) {
        if (unique_symbols.at(i) != decode_data.at(i)) {
            decode_success = false;
            break;
        }
    }

    if (decode_success) std::cout << "Decoding Process Success!" << std::endl;
    else std::cout << "Decoding Process Fail!" << std::endl;

    std::cout << "Original Size : " << original_data.size() * BYTE << "[bits]" << std::endl;
    std::cout << "Comprssed Bitstream Size : " << comprssed_bitstream.size() << "[bits]" << std::endl;
    std::cout << "Comprssion Ratio : " << DATA::get_cr(original_data, comprssed_bitstream) << std::endl;

    delete huffman_tree;

    return 0;
}
