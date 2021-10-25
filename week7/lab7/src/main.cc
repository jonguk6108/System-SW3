#include "string.h"
#include <iostream>

int main() {

    char a[1000] = "This is a ";
    char b[1000] = "test program.";

    String A = a, B = b;

    std::cout << "A : ";
    A.print();
    std::cout << std::endl;

    std::cout << "B : ";
    B.print();
    std::cout << std::endl;

    std::cout << "A + B : ";
    String C;
    C = A+B;
    //C = split(C," ");
    C.print();
    std::cout << std::endl;

    std::cout << "split :";
    std::vector<String> AA = split(C, ' ');
    for(int haha =0; haha < AA.size(); haha++)
        AA[haha].print();
    std::cout << std::endl;

    std::cout << "A + 'test!'";
    (A + "test!").print();
    std::cout << std::endl;

    std::cout << "A += B : ";
    A += B;
    A.print();
    std::cout << std::endl;

    std::cout << "B * 2 : ";
    (B * 2).print();
    std::cout << std::endl;

    std::cout << "B *= 2 : ";
    B *= 2;
    B.print();
    std::cout << std::endl;

    A = a;
    B = b;

    std::cout << "A[0] : " << A[0] << std::endl;

    std::cout << "A << 2 : ";
    (A << 2).print();
    std::cout << std::endl;

    std::cout << "A >> 2 : ";
    (A >> 2).print();
    std::cout << std::endl;

    std::cout << "A == B : " << (A==B) << std::endl;
    std::cout << "A != B : " << (A!=B) << std::endl;

}
