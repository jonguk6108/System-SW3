#include <iostream>
#include <iomanip>
#include <string>

#include "stringlib.hh"

class Tester{

public:
    Tester(){}

    template <typename T1, typename T2>
    void test_startsWith(T1 target_str, T2 src_str){
        if(startsWith(target_str, src_str))
            std::cout << target_str << " starts with " << src_str << std::endl;
        else
            std::cout << target_str << " not starts with " << src_str << std::endl;
    }

    template <typename T1, typename T2>
    void test_endsWith(T1 target_str, T2 src_str){
        if(endsWith(target_str, src_str))
            std::cout << target_str << " ends with " << src_str << std::endl;
        else
            std::cout << target_str << " not ends width " << src_str << std::endl;
    }

    void test_integerToString(int n);

    void test_realToString(double d);

    void test_stringToInteger(std::string str);

    void test_stringToReal(std::string str);

    void test_toLowerCase(std::string str);

    void test_toUpperCase(std::string str);

    void test_compareIgnoreCaseType(std::string s1, std::string s2);

    void test_trim(std::string str);

    void printState(std::string test_str);

    void printSpace();
};
