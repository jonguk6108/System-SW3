/* *************************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : data.h
 * - File Type : c++ header code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is provided data processing header code for SSE2034-41(SKKU, 2021) class HW 10.
 *                 Do not modify this code! Do not distribute this code without permission.
 * *************************************************************************************************************/

#ifndef DATA_H
#define DATA_H

#include <vector>
#include <fstream>
#include <string>

const size_t BYTE = 8;

namespace DATA {

    std::vector<uint8_t> get_data(std::string file_name);

    double get_cr(std::vector<uint8_t> original_data, std::string comprssed_bitstream);
}

#endif
