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

typedef struct METADATA {
    size_t at_row;
    size_t at_col;
    int update_data;
    std::string range;
    std::vector<int> update_datas;
    bool is_pm, is_mul;
} metadata;

metadata *get_metadata(std::string line)
{
    using namespace std;
    vector<string> decode;

    size_t start = 0;

    for (size_t i=0; i<line.size(); i++)
    {
        if (line.at(i) == ' ') {
            decode.push_back(line.substr(start, i-start));
            start = i+1;
        }
    }

    if (start != line.size()) {
        decode.push_back(line.substr(start));
    }

    metadata *decode_meta = new metadata;

    if (decode.at(0) != "M") return NULL;

    decode_meta->at_row = stoi(decode.at(1));
    decode_meta->at_col = stoi(decode.at(2));
    decode_meta->update_data = stoi(decode.at(3));
    decode_meta->range = decode.at(4);
    
    size_t size = stoi(decode.at(5));

    decode_meta->update_datas.clear();

    for (size_t i=0; i<size; i++) {
        decode_meta->update_datas.push_back(stoi(decode.at(6+i)));
    }

    return decode_meta;
}

int main (int argc, char *argv[])
{
    using namespace std;

    ifstream input_file(argv[1]);
    ifstream metadata_file(argv[2]);

    while (true){
        vector<int> a;
        vector<int> b;

        size_t row_a, row_b, col_a, col_b;

        char Mat_C;
        
        input_file >> Mat_C;

        if (Mat_C == 'E') {
            //cout << "End!" << endl;
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

        cout << "______________________________________________________________________________________________\n" << endl;

        MATRIX A = MATRIX(a, row_a, col_a);
        MATRIX B = MATRIX(b, row_b, col_b);

        string line;
         getline(metadata_file, line);
        metadata *cur_meta = get_metadata(line);

        if ((row_a == row_b) && (col_a == col_b)) cur_meta->is_pm = true;
        else cur_meta->is_pm = false;

        if (col_a == row_b) cur_meta->is_mul = true;
        else cur_meta->is_mul = false;

        cout << "A : " << A.to_string() << "\nB : " << B.to_string() << endl;

        if(cur_meta->is_pm) {
            cout << "A + B = " << (A + B).to_string() << endl;
            cout << "A - B = " << (A - B).to_string() << endl;

            MATRIX C = A;

            C += B;
            cout << "C=A...\nC += B -> C = " << C.to_string() << endl;
            C -= B;
            cout << "C -= B -> C = " << C.to_string() << endl;

            cout << (A==B) << (A==A) << (A!=A) << (A!=B) << endl;
            cout << (A>B) << (A<B) << (A>=B) << (A<=B) << endl;
        }

        if (cur_meta->is_mul)
        {
            cout << "A * B = " << (A*B).to_string() << endl;

            MATRIX C = A;
            C *= B;
            cout << "C = A;\nC *= B -> C = " << C.to_string() << endl;
        }

        cout << "A + 2 = " << (A+2).to_string() << endl;
        cout << "B - 2 = " << (B-2).to_string() << endl;
        cout << "A * 2 = " << (A*2).to_string() << endl;

        MATRIX C = A;
        cout << "C=A;" << endl;

        C += 2;
        cout << "C += 2 -> C =" << C.to_string() << endl;
        C -= 2;
        cout << "C -= 2 -> C = " << C.to_string() << endl;
        C *= -1;
        cout << "C *= -1 -> C = " << C.to_string() << endl;

        cout << "A.at(" << cur_meta->at_row << "," << cur_meta->at_col << ") = " << A.at(cur_meta->at_row, cur_meta->at_col) << endl;
        A.at(cur_meta->at_row, cur_meta->at_col, cur_meta->update_data);
        cout << "Update at(row, col) to " << cur_meta->update_data << " : " << A.to_string() << endl;
        cout << "A.at(" << cur_meta->range << ") = " << A.at(cur_meta->range).to_string() << endl;
        A.at(cur_meta->range, cur_meta->update_datas);
        cout << "Update at(range) to : " << A.to_string() << endl;

        cout << "B[" << cur_meta->range << "] = " << (B[cur_meta->range]).to_string() << endl;

        delete cur_meta;

        cout << "______________________________________________________________________________________________\n" << endl;
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

