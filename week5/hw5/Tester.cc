#include "Tester.hh"

void Tester::test_integerToString(int n){
    
    std::string str = integerToString(n);
    std::cout << "integerToString(): " << n << " --> " << str << std::endl;
}

void Tester::test_realToString(double d){
    std::string str = realToString(d);
    std::cout << "realToString(): " << d << " --> " << str << std::endl;
}

void Tester::test_stringToInteger(std::string str){
    int n = stringToInteger(str);
    std::cout << "stringToInteger(): " << str << " --> " << n << std::endl;
}

void Tester::test_stringToReal(std::string str){
    double d = stringToReal(str);
    std::cout << "stringToReal(): " << str << " --> " << d << std::endl;
}

void Tester::test_toLowerCase(std::string str){
    std::string new_str = toLowerCase(str);
    std::cout << "toLowerCase(): " << str << " --> " << new_str << std::endl;
}

void Tester::test_toUpperCase(std::string str){ 
    std::string new_str = toUpperCase(str);
    std::cout << "toUpperCase(): " << str << " --> " << new_str << std::endl;
}

void Tester::test_compareIgnoreCaseType(std::string s1, std::string s2){    
    if(comapreIgnoreCaseType(s1, s2))
        std::cout << s1 << " and " << s2 << " are the same string " << std::endl;
    else
        std::cout << s1 << " and " << s2 << " are not the same string " << std::endl;
}

void Tester::test_trim(std::string str){
    std::cout << "The target of trim(): " << str << std::endl;
    std::vector<std::string> str_vec = trim(str);
    
    int i=0;
    for(auto it = str_vec.begin(); it != str_vec.end(); it++){
        std::cout << "str_vec[" << i << "]: " << *it << std::endl;
        i+=1;
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
