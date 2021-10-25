//DO NOT MODIFY THIS FILE
#include "matrix.h"
#include <cassert>

bool is_greater_than(MATRIX A, MATRIX B)
{
    assert(A.data_array.size() == B.data_array.size() && "Size is not equal!");

    int sum_a = 0;
    int sum_b = 0;

    for (size_t i=0; i<A.data_array.size(); i++) {
        sum_a += A.data_array.at(i);
        sum_b += B.data_array.at(i);
    }

    if (sum_a > sum_b) return true;
    else return false;
    
}

bool is_smaller_than(MATRIX A, MATRIX B)
{
    assert(A.data_array.size() == B.data_array.size() && "Size is not equal!");

    int sum_a = 0;
    int sum_b = 0;

    for (size_t i=0; i<A.data_array.size(); i++) {
        sum_a += A.data_array.at(i);
        sum_b += B.data_array.at(i);
    }

    if (sum_a < sum_b) return true;
    else return false;
 
}

bool operator > (MATRIX A, MATRIX B) { return is_greater_than(A, B);}

bool operator < (MATRIX A, MATRIX B) { return is_smaller_than(A, B);}

bool operator >= (MATRIX A, MATRIX B)
{   
    if (A < B) return false;
    else return true;
}

bool operator <= (MATRIX A, MATRIX B)
{
    if (A > B) return false;
    else return true;
}
