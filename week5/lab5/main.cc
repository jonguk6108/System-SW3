#include "Tester.hh"

int main(){

    int A[N][N]
     = { {1,  2,  3,  4,  5},
         {6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    int B[N][N]
     = {{25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10,  9,  8,  7,  6},
        {5,  4,  3,  2,  1}};

    int C[N][N] = {0,};
    int A_T[N][N] = {0,};

    
    // Call Tester instance
    Tester* tt = new Tester();

    tt->test_matEqual(A, B);
    tt->test_matAdd(A, B, C);
    tt->test_matSub(A, B, C);
    tt->test_matMul(A, B, C);
    tt->test_transpose(A, A_T);
    tt->test_matrixToString(A);
    
}