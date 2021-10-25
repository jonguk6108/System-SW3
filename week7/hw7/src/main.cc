//DO NOT MODIFY THIS FILE

#include <iostream>
#include <cassert>
#include "matrix.h"
#include <vector>
#include <string>
#include <fstream>

#ifdef COMPARE_SUM
#include "compare_sum.h"
#elif defined COMPARE_FIRST
#include "compare_first.h"
#else
#define MY_COMPARE
#endif

int main (int argc, char *argv[])
{
    using namespace std;

    ifstream input_file(argv[1]);

    while (true){
        vector<int> a;
        vector<int> b;

        size_t row_a, row_b, col_a, col_b;

        char Mat_C;
        
        input_file >> Mat_C;

        if (Mat_C == 'E') {
            cout << "End!" << endl;
            break;
        } else if (Mat_C == 'S') {
            size_t size;

            input_file >> row_a >> col_a;

            size = row_a * col_a;

            for (size_t i=0; i<size; i++)
            {
                int elem;
                input_file >> elem;

                a.push_back(elem);
            }

            input_file >> row_b >> col_b;

            size = row_b * col_b;

            for (size_t i=0; i<size; i++)
            {
                int elem;
                input_file >> elem;

                b.push_back(elem);
            }
        } else {
            cout << "input_file error!" << endl;
            break;
        }

        cout << "-------------------------------------PRINT Result!------------------------------------------" << endl;
        MATRIX A = MATRIX(a, row_a, col_a);
        MATRIX B = MATRIX(b, row_b, col_b);

        cout << "A : " << A.to_string() << endl;
        cout << "B : " << B.to_string() << endl;

        cout << "A.at(0, 0) : " << A.at(0, 0) << endl;
        cout << "B.at (:, 1) : " << B.at(":,1").to_string() << endl;

        cout << "A[0,0] : " << A["0,0"].to_string() << endl;
        cout << "B[:,1] : " << B[":,1"].to_string() << endl;
        cout << "A[0:2, 0] : " << A["0:2,0"].to_string() << endl;
        cout << "A + B : " << (A+B).to_string() << endl;
        cout << "A - B : " << (A-B).to_string() << endl;
        cout << "B - A : " << (B-A).to_string() << endl;
        cout << "A * B : " << (A*B).to_string() << endl;

        cout << "A + 2 : " << (A+2).to_string() << endl;
        cout << "A - 2 : " << (A-2).to_string() << endl;
        cout << "2 - A : " << (2-A).to_string() << endl;
        cout << "A * 2 : " << (A*2).to_string() << endl;

        cout << "A == B : " << (A==B) << endl;
        cout << "A != B : " << (A!=B) << endl;
        cout << "A > B : " << (A>B) << endl;
        cout << "A < B : " << (A<B) << endl;
        cout << "A >= B : " << (A>=B) << endl;
        cout << "A <= B : " << (A <=B) << endl;
        vector<int> data;

        for (size_t i=0; i<row_a; i++) {
            for (size_t j=0; j<row_b; j++) {
                data.push_back(0);
            }
        }

        cout << "Initialize A to all zero : ";
        A.at(":,:", data);
        cout << A.to_string() << endl;

        cout << "A += B -> A : ";
        A += B;
        cout << A.to_string() << endl;

        cout << "A *= B -> A : ";
        A *= B;
        cout << A.to_string() << endl;

        cout << " A -= B -> A : ";
        A -= B;
        cout << A.to_string() << endl;

        cout << "B *= 0 -> B : ";
        B *= 0;
        cout << B.to_string() << endl;

        cout << "B += 1 -> B : ";
        B += 1;
        cout << B.to_string() << endl;

        cout << "B -= 1 -> B : ";
        B -= 1;
        cout << B.to_string() << endl;
        cout << "------------------------------------------------------------------------------------------\n" << endl; 
    }

    input_file.close();

    return 0;
}

#ifdef MY_COMPARE
bool is_greater_than(MATRIX A, MATRIX B)
{
    return (A.n_row * A.n_col) > (B.n_row * B.n_col);
}

bool is_smaller_than(MATRIX A, MATRIX B)
{
    return (A.n_row * A.n_col) < (B.n_row * B.n_col);
}

bool operator > (MATRIX A, MATRIX B) { return is_greater_than(A, B); }

bool operator < (MATRIX A, MATRIX B) { return is_smaller_than(A, B); }

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
#endif

