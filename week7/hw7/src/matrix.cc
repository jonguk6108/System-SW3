#include "matrix.h"

MATRIX::MATRIX(void)
{
    n_row = 0;
    n_col = 0;
    data_array.clear();
}

MATRIX::MATRIX(size_t row_size, size_t col_size)
{
    n_row = row_size;
    n_col = col_size;

    data_array.resize(row_size * col_size, 0);
}

MATRIX::MATRIX(std::vector<int> data, size_t row_size, size_t col_size)
{
    size_t array_size = data.size();

    n_row = row_size;
    n_col = col_size;

    data_array.resize(array_size);

    for (size_t i=0; i<array_size; i++) data_array.at(i) = data.at(i);
}

std::string MATRIX::to_string() const
{
    std::string result = "{";

    for (size_t row = 0; row < n_row; row++) {

        for (size_t col = 0; col < n_col; col ++) {

            if (col == 0) result += "{";

            result += std::to_string(data_array.at(row * n_col + col));

            if (col != (n_col - 1)) result += ", ";
        }

        result += "}";

        if (row != (n_row-1)) result += ", ";
        else result += "}";
    }

    return result;
}

size_t MATRIX::get_size() const {return n_row * n_col;}

std::vector <size_t> MATRIX::get_dimension() const
{
    std::vector <size_t> dimension(2, 0);

    dimension.at(0) = n_row;
    dimension.at(1) = n_col;

    return dimension;
}


int MATRIX::at(size_t r, size_t c) const
{
    return data_array[r*n_col + c];
}


void MATRIX::at(size_t r, size_t c, int d)
{
    data_array[r*n_col + c] = d;
}

void MATRIX::findsf(std::string s, size_t *a, size_t *b, size_t *c, size_t *d) const
{
    std::string s1;
    std::string s2;
    size_t rs = 0, rf = 0, cs = 0, cf = 0;
    size_t com = s.find(",");
    size_t semi;
    s1 = s.substr(0, com);
    semi = s1.find(":");
    if(semi < 0 || semi > 100000) {
        rs = stoi(s1);
        rf = rs;
    }
    else {
        s2 = s1.substr(semi+1, com-1);
        s1 = s.substr(0, semi);

        if(s1.size() != 0)
            rs = stoi(s1);
        if(s2.size() != 0)
            rf = stoi(s2) - 1;
        if(s1.size() == 0)
            rs = rf;
        if(s2.size() == 0)
            rf = rs;
        if(s1.size() == 0 && s2.size() == 0) {
            rs = 0;
            rf = n_row - 1;
        }
    }

    s1 = s.substr(com + 1, s.size() - (com + 1));
    semi = s1.find(":");
    if(semi < 0 || semi > 100000) {
        cs = stoi(s1);
        cf = cs;
    }
    else {
        s2 = s1.substr(semi+1, com-1);
        s1 = s.substr(0, semi);

        if(s1.size() != 0)
            cs = stoi(s1);
        if(s2.size() != 0)
            cf = stoi(s2);
        if(s1.size() == 0)
            cs = cf -1;
        if(s2.size() == 0)
            cf = cs;
        if(s1.size() == 0 && s2.size() == 0) {
            cs = 0;
            cf = n_row - 1;
        }
    }
   
    *a = rs;
    *b = rf;
    *c = cs;
    *d = cf;
    return;
}

MATRIX MATRIX::at(std::string range) const
{
    std::vector <int> d;
    size_t rs = 0, rf = 0, cs = 0, cf = 0;
    (*this).findsf(range, &rs, &rf, &cs, &cf);
    std::vector<int> tmp;
    for(size_t i = rs; i <= rf; i++)
        for(size_t j = cs; j <= cf; j++)
            tmp.push_back( (*this).at(i, j) );
    MATRIX ans = MATRIX(tmp, rf-rs+1, cf-cs+1);
    return ans;
}

void MATRIX::at(std::string range, std::vector<int> data) {
    size_t rs = 0, rf = 0, cs = 0, cf = 0;
    (*this).findsf(range, &rs, &rf, &cs, &cf);

    size_t di = 0;
    for(size_t i = rs; i <= rf; i++)
        for(size_t j = cs; j <= cf; j++) {
            (*this).data_array[i*n_col + j] = data[di];
            di++;
        }
    
    return;
}


MATRIX MATRIX::operator [](std::string range) const{
    return (*this).at(range);
}

MATRIX MATRIX::operator +( MATRIX rhs ) {
    std::vector<int> data_ans;
    for(size_t i = 0; i < n_row; i++)
        for(size_t j = 0; j < n_col; j++) 
            data_ans.push_back( (*this).at(i, j) + rhs.at(i, j) );
    MATRIX ans = MATRIX(data_ans, n_row, n_col);
    return ans;
}

MATRIX MATRIX::operator -( MATRIX rhs ) {
    std::vector<int> data_ans;
    for(size_t i = 0; i < n_row; i++)
        for(size_t j = 0; j < n_col; j++) 
            data_ans.push_back( (*this).at(i, j) - rhs.at(i, j) );
    MATRIX ans = MATRIX(data_ans, n_row, n_col);
    return ans;
}

MATRIX MATRIX::operator *( MATRIX rhs ) {
    std::vector<int> data_ans;
    std::vector<size_t> rhs_size = rhs.get_dimension();

    int tmp = 0;
    for(size_t i = 0; i < n_row; i++) {
        for(size_t j = 0; j < rhs_size[1]; j++) {
            tmp = 0;
            for(size_t k = 0; k < n_col; k++)
                tmp += (*this).at(i, k) * rhs.at(k, j);
            data_ans.push_back( tmp );
        }
    }
    MATRIX ans = MATRIX(data_ans, n_row, n_row);
    return ans;
}

void MATRIX::operator +=( MATRIX rhs ) {
    (*this) = (*this) + rhs;
}
void MATRIX::operator -=( MATRIX rhs ) {
    (*this) = (*this) - rhs;
}
void MATRIX::operator *=( MATRIX rhs ) {
    (*this) = (*this) * rhs;
}

MATRIX MATRIX::operator +( int b ) {
    std::vector<int> data_ans;
    for(size_t i = 0; i < n_row; i++)
        for(size_t j = 0; j < n_col; j++) 
            data_ans.push_back( (*this).at(i, j) + b);
    MATRIX ans = MATRIX(data_ans, n_row, n_col);
    return ans;   
}

MATRIX MATRIX::operator -( int b ) {return (*this) + (-b);}

MATRIX MATRIX::operator *( int b ) {
    std::vector<int> data_ans;
    for(size_t i = 0; i < n_row; i++)
        for(size_t j = 0; j < n_col; j++) 
            data_ans.push_back( (*this).at(i, j) * b);
    MATRIX ans = MATRIX(data_ans, n_row, n_col);
    return ans;   
}

void MATRIX::operator +=( int b ) {
    (*this) = (*this) + b;
}
void MATRIX::operator -=( int b ) {
    (*this) = (*this) - b;
}
void MATRIX::operator *=( int b ) {
    (*this) = (*this) * b;
}

bool MATRIX::operator ==( MATRIX rhs ) {
    std::vector<size_t> rhs_size = rhs.get_dimension();
    if(n_row != rhs_size[0] || n_col != rhs_size[1]) return false;

    std::vector<int> data_ans;
    for(size_t i = 0; i < n_row; i++)
        for(size_t j = 0; j < n_col; j++) 
            if(data_array[i*n_col + j] != rhs.at(i,j))
                return false;
    return true;
}

bool MATRIX::operator !=( MATRIX rhs ) {return !( (*this) == rhs );}
