#include <iostream>
#include <iomanip>
#include <string>

#include "param.hh"
#include "matrixlib.hh"

class Tester{

public:
    Tester(){}

    void test_matEqual(int A[][N], int B[][N]);
    void test_matAdd(int A[][N], int B[][N], int C[][N]);
    void test_matSub(int A[][N], int B[][N], int C[][N]);
    void test_matMul(int A[][N], int B[][N], int C[][N]);
    void test_transpose(int A[][N], int A_T[][N]);
    void test_matrixToString(int A[][N]);


protected:
    void printMatrix(int A[][N]);

    void printState(std::string test_str);

    void printSpace();

};
