#include "Student.hh"

void Student::put_grade(Grade g_) {g.push_back(g_);}
void Student::put_old(bool old_) {old = old_;}
bool Student::check_tmp() {
    bool ans;

    double total = 0;
    for(int i = 0; i < n; i ++) {
        total += g[i].a;
        if(g[i].a == 0)
            return false;
    }
    total = total / n;
    if(total < 3) return false;

    int size = 0;
    for(int i = 0; i < n; i ++)
        size += g[i].b;
    
    if(size < 9) return false;
    if(size < 12 && current != 7) return false;

    return true;
}
void Student::check() {
    bool ans = check_tmp();
    if(current == 8) {
        std::cout << "PF" << std::endl;
        return;
    }
    if(current > 3 && sn >= 19) {
        std::cout << "PF" << std::endl;
        return;
    }
    if(ans == true) {
        std::cout << "T" << std::endl;
        return;
    }
    if(old == false) {
        std::cout << "PF" << std::endl;
        return;
    }
    std::cout << "F" << std::endl;
    return;

}
