#include "string.h"
#include <iostream>

String::String() {char_array.clear();}

String::String(char str[])
{
    size_t i=0;

    while (str[i] != '\0') {
        char_array.push_back(str[i]);
        i++;
    }
}

String::String(std::vector<char> str) {char_array = str;}

size_t String::len() {
    size_t size = char_array.size();

    return size;
}

char String::at(size_t idx) {return char_array.at(idx);}

void String::set(size_t idx, char c) {char_array.at(idx) = c;}

size_t String::find(char c) {

    size_t i;

    for (i=0; i<char_array.size(); i++){
        if (char_array.at(i) == c) return c;
    }

    return i;
}

size_t String::end() {return (size_t)char_array.size();}

void String::print(){
    for (size_t i=0; i<char_array.size(); i++) {
        std::cout << char_array.at(i);
    }
}

void print(String str) {
    str.print();
}

std::vector<String> split(String str, char divide){
    std::vector<String> ans;
    String s;
    std::vector<char> tmpc;

    size_t i = 0;
    while(1) {
        if(str.end() == i) {
            s = tmpc;
            ans.push_back(s);
            return ans;
        }
        if( str.at(i) == divide) {
            s = tmpc;
            ans.push_back(s);
            tmpc.clear();
            i++;
            continue;
        }
        tmpc.push_back( str.at(i) );
        i++;
    }
}

String String::operator +(String rhs) {
    std::vector<char> tmpc;
    for(size_t i = 0; i < len(); i++)
        tmpc.push_back(at(i));
    for(size_t i = 0; i < rhs.len(); i++)
        tmpc.push_back(rhs.at(i));
    String ans(tmpc);
    return ans;
}

String String::operator +( char rhs[]) {
    std::vector<char> tmpc;
    for(size_t i = 0; i < len(); i++)
        tmpc.push_back(at(i));
    for(size_t i = 0; rhs[i] != '\0'; i++)
        tmpc.push_back(rhs[i]);
    String ans(tmpc);
    return ans;
}

void String::operator += (String rhs) {
    for(size_t i = 0; i < rhs.len(); i++)
        char_array.push_back(rhs.at(i));
}

void String::operator += (char rhs[]) {
    for(size_t i = 0; rhs[i] != '\0'; i++)
        char_array.push_back(rhs[i]);
}

void String::operator =(char rhs[]) {
    char_array.clear();
    for(size_t i = 0; rhs[i] != '\0'; i++)
        char_array.push_back(rhs[i]);
    //TODO : assign *this as rhs;
}

void String::operator =(std::vector<char> rhs) {
    char_array.clear();
    for(size_t i = 0; i < rhs.size(); i++)
        char_array.push_back(rhs[i]);
    //TODO : assign *this as rhs
}

String String::operator *(unsigned rhs) {
    std::vector<char> tmp;
    for(unsigned i = 0; i < rhs; i++)
        for(size_t j = 0; j < len(); j++)
            tmp.push_back(at(j));
    String ans(tmp);
    return ans;
}

void String::operator *= (unsigned rhs) {
    String orichar = *this;
    size_t orilen = len();
    std::vector<char> tmp;
    *this = tmp;
    for(unsigned i = 0; i < rhs; i++)
        for(size_t j = 0; j < orilen; j++)
            char_array.push_back(orichar.at(j));
}

char String::operator [](size_t rhs) const{
    return (*this).char_array[rhs];
    //TODO : return rhs index character in *this
}

String String::operator <<(size_t rhs) {
    std::vector<char> tmp;
    for(size_t j = 0; j < len(); j++)
        tmp.push_back(at(j));
    std::vector<char> tmpp;
    for(size_t i = 0; i < rhs; i++) {
        tmpp.push_back(tmp[0]);
        for(size_t j = 1; j < len(); j++)
            tmp[j-1] = tmp[j];
        tmp[len()-1] = tmpp[i];
    }
    String ans(tmp);
    return ans;
}

String String::operator >>(size_t rhs) {
    std::vector<char> tmp;
    for(size_t j = 0; j < len(); j++)
        tmp.push_back(at(j));
    std::vector<char> tmpp;
    for(size_t i = 0; i < rhs; i++) {
        tmpp.push_back(tmp[len()-1]);
        for(size_t j = len()-1; j > 0; j--)
            tmp[j] = tmp[j-1];
        tmp[0] = tmpp[i];
    }
    String ans(tmp);
    return ans;
}

bool String::operator ==(String rhs) {
    if(len() != rhs.len()) return false;
    for(size_t i = 0; i < len(); i++)
        if(at(i) != rhs.at(i))
            return false;
    return true;
    //TODO : if all characters are same -> return true
}

bool String::operator !=(String rhs) {
    return !(*this == rhs);
    //TODO : if !(lhs == rhs) -> return true
}


