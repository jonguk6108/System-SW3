#include "matrixlib.hh"

bool matEqual(int A[][N], int B[][N]){
    for(int i = 0; i < N; i++ ) {
        for(int j = 0; j < N; j++) {
            if(A[i][j] != B[i][j]) return false;
        }
    }
    return true;
    // TODO: Fill your code here.
   
}

void matAdd(int A[][N], int B[][N], int C[][N]){
    for(int i = 0; i < N; i++ ) {
        for(int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    // TODO: Fill your code here.
    
}

void matSub(int A[][N], int B[][N], int C[][N]){
    for(int i = 0; i < N; i++ ) {
        for(int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    
    // TODO: Fill your code here.
    
}

void matMul(int A[][N], int B[][N], int C[][N]){
    for(int i = 0; i < N; i++ ) {
        for(int j = 0; j < N; j++) {
            C[i][j] = 0;
            for(int k = 0; k < N; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    // TODO: Fill your code here.
    
}

void transpose(int A[][N], int A_T[][N]){

    for(int i = 0; i < N; i++ ) {
        for(int j = 0; j < N; j++) {
            A_T[j][i] = A[i][j];
        }
    }
    // TODO: FiLL your code here
    
}

std::string matrixToString(int A[][N]){
    //TODO: Fill your code here
    //Hint: Use function std::to_string
    std::string ans;
    for(int i = 0; i < N; i++) {
        ans = ans + '{';
        for(int j = 0; j < N; j++) {
            ans = ans + std::to_string(A[i][j]);
            if(j == N-1 && i == N-1) {
                ans = ans + '}';
                return ans;
            }
            if(j == N-1) ans = ans + '}' + ',' + '\n';
            else ans = ans + ',';
        }
    } 
}
