#include "Tester.hh"

void Tester::test_matEqual(int A[][N], int B[][N]){
    printState("1. matEqual() ");
    if(matEqual(A,B))
        std::cout << "Matrix A is equal to B" << std::endl;
    else
        std::cout << "Matrix A differs to B" << std::endl;
    
    if(matEqual(A,A))
        std::cout << "Matrix A is equal to A" << std::endl;
    else
        std::cout << "Matrix A differs to A" << std::endl;
    printSpace();
}


void Tester::test_matAdd(int A[][N], int B[][N], int C[][N]){
    printState("2. matAdd() ");
    matAdd(A, B, C);
    std::cout << "Mat Add A + B = " << std::endl;
    printMatrix(C);
    printSpace();
}


void Tester::test_matSub(int A[][N], int B[][N], int C[][N]){
    printState("3. matSub() ");
    matSub(A, B, C);
    std::cout << "Mat Add A - B = " << std::endl;
    printMatrix(C);
    printSpace();
}


void Tester::test_matMul(int A[][N], int B[][N], int C[][N]){
    printState("4. matMul() ");
    matMul(A, B, C);
    std::cout << "Mat Add A * B = " << std::endl;
    printMatrix(C);
    printSpace();

}

void Tester::test_transpose(int A[][N], int A_T[][N]){
    printState("5. transpose() ");
    transpose(A, A_T);
    std::cout << " A.T = " << std::endl;
    printMatrix(A_T);
    printSpace();
}

void Tester::test_matrixToString(int A[][N]){
    printState("6. matrixToString() ");
    std::string str = matrixToString(A);
    std::cout << " The string format of matrix A is :  " << std::endl;
    std::cout << str << std::endl;
    printSpace();
}


void Tester::printMatrix(int A[][N]){
    
    for(int i=0; i<N; i++){
        std::cout << std::setw(10) << i <<"th Row: ";
        for(int j=0; j<N; j++){
            std::cout << std::setw(4) << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Tester::printState(std::string test_str){
    std::cout<<"----------------------------------------------------------"<<std::endl;
    std::cout<< std::setw(30) << test_str << std::endl;
    std::cout<<"----------------------------------------------------------"<<std::endl;
}

void Tester::printSpace(){
    std::cout << std::endl << std::endl;
}
