/* *************************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : data.cc
 * - File Type : c++ header code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is provided data processing code for SSE2034-41(SKKU, 2021) class HW 10.
 *                 Do not modify this code! Do not distribute this code without permission.
 * *************************************************************************************************************/

#include "data.h"

std::vector<uint8_t> DATA::get_data(std::string file_name) {

    using namespace std;

    ifstream input_bin(file_name, ifstream::binary);

    std::vector <uint8_t> ret;

    while (true) {
        uint8_t buffer;

        input_bin.read((char *)&buffer, 1);

        if (input_bin.eof()) {
            input_bin.close();
            break;
        }

        ret.push_back(buffer);
    }

    return ret;

}

double DATA::get_cr(std::vector<uint8_t>original_data, std::string compressed_bitstream) {

    size_t original_size = original_data.size() * BYTE;

    size_t comprssed_size = compressed_bitstream.size();

    return (double)original_size / comprssed_size;
}
