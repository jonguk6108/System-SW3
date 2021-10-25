#include "calculator.h"

int main(int argc, char **argv){
    if(!strcmp(argv[1],"add"))
        std::cout << argv[2] << "+" << argv[3]<< " is " << adder(atoi(argv[2]),atoi(argv[3])) << std::endl;
    else if(!strcmp(argv[1],"mul"))
        std::cout << argv[2] << "*" << argv[3] << " is " << multiplier(atoi(argv[2]),atoi(argv[3])) << std::endl;
    else if(!strcmp(argv[1],"sub"))
        std::cout << argv[2] << "-" << argv[3] << " is " << subtractor(atoi(argv[2]),atoi(argv[3])) << std::endl;
    else
        std::cout << "invalid type" << std::endl;

}
