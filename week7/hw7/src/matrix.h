

//You can write code in any part except between /***********/ region.
//You cannot include any other libraries except vector and string.
/********************************************************************************************/
#ifndef MATRIX_H 
#define MATRIX_H


#include <vector>
#include <string>

class MATRIX {

    private:
    size_t n_row, n_col;
    std::vector <int> data_array;

    public:
    MATRIX(void);
    MATRIX(size_t row_size, size_t col_size);

    MATRIX(std::vector<int> data, size_t row_size, size_t col_size);
    std::string to_string() const;
    size_t get_size() const;
    std::vector <size_t> get_dimension() const;
    int at(size_t r, size_t c) const;
    void at(size_t r, size_t c, int d);

    void findsf(std::string s, size_t *a, size_t *b, size_t *c, size_t *d) const;
    MATRIX at(std::string range) const;
    void at(std::string range, std::vector<int> data);
    MATRIX operator [](std::string range) const;
    MATRIX operator + (MATRIX rhs);
    MATRIX operator - (MATRIX rhs);
    MATRIX operator * (MATRIX rhs);
    void operator += (MATRIX rhs);
    void operator -= (MATRIX rhs);
    void operator *= (MATRIX rhs);
    MATRIX operator +( int b );
    MATRIX operator -( int b );
    MATRIX operator *( int b );
    void operator +=( int b );
    void operator -=( int b );
    void operator *=( int b );
    bool operator ==( MATRIX rhs );
    bool operator !=( MATRIX rhs );
    


    friend MATRIX operator + (int B, MATRIX A) { return A+B;};
    friend MATRIX operator - (int B, MATRIX A) { 
        MATRIX C = A;
        C *= 0;
        C += 1;
        C *= B;
        return C - A;};















    
    friend bool is_greater_than(MATRIX A, MATRIX B);
    friend bool is_smaller_than(MATRIX A, MATRIX B);
    friend bool operator > (MATRIX A, MATRIX B);
    friend bool operator < (MATRIX A, MATRIX B);
    friend bool operator >= (MATRIX A, MATRIX B);
    friend bool operator <= (MATRIX A, MATRIX B);
};

#endif
/********************************************************************************************/
