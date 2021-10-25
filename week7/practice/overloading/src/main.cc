#include "time.h"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    unsigned h1, m1, s1, h2, m2, s2;

    h1 = std::stoi(argv[1]);
    m1 = std::stoi(argv[2]);
    s1 = std::stoi(argv[3]);

    h2 = std::stoi(argv[4]);
    m2 = std::stoi(argv[5]);
    s2 = std::stoi(argv[6]);

    Time t1 = Time(h1, m1, s1, false);
    Time t2 = Time(h2, m2, s2, false);

    std::cout << "t1 : ";
    t1.print();

    std::cout << "t2 : ";
    t2.print();

    std::cout << "t1 + t2 : ";
    (t1 + t2).print();

    std::cout << "t1 - t2 : ";
    (t1 - t2).print();

    std::cout << "t1 == t2 : " << (t1 == t2) << std::endl;
    std::cout << "t1 > t2 : " << (t1 > t2) << std::endl;
    std::cout << "t1 < t2 : " << (t1 < t2) << std::endl;
    std::cout << "t1 >= t2 : " << (t1 >= t2) << std::endl;
    std::cout << "t1 <= t2 : " << (t1 <= t2) << std::endl;

    std::cout << "t1 + 100 : ";
    (t1 + 100).print();

    std::cout << "t1 - 100 : ";
    (t1 - 100).print();

    std::cout << "100 - t1 : ";
    (100 - t1).print();

}
