#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>
using namespace std;

class Poly{
    public:
        Poly(int max_exp_, int* coefficient_);
        void Print_poly();
        ~Poly();
        int Get_max();
        int Get_ico(int i);
        Poly operator + (Poly &rhs);
        Poly operator - (Poly &rhs);
        Poly operator * (Poly &rhs);
        

    private:
        int* coefficient;
        int max_exp;
};
Poly::Poly(int max_exp_, int* coefficient_) {
    max_exp = max_exp_; 
    coefficient = new int[max_exp];
    for(int i = 0; i < max_exp; i++)
        coefficient[i] = coefficient_[i];
}
void Poly::Print_poly() {
    for(int i = 0; i < max_exp; i++) {
        if(i != 0)
            cout << " ";
        cout << coefficient[i];
    }
    return;
}
Poly::~Poly() {
    delete [] coefficient;
}
int Poly::Get_max() { return max_exp; }
int Poly::Get_ico(int i) { return coefficient[i]; }
Poly Poly::operator + (Poly &rhs) {
    int cmax = max_exp;
    if(cmax < rhs.Get_max())
        cmax = rhs.Get_max();
    int ctmp[cmax];
    for(int i = 0 ; i < cmax; i++)
        ctmp[i] = 0;
    for(int i = 0 ; i < max_exp; i++)
        ctmp[i] = coefficient[i];
    for(int i = 0 ; i < rhs.Get_max(); i++)
        ctmp[i] += rhs.Get_ico(i);
    Poly ptmp(cmax, ctmp);
    return ptmp;
}
Poly Poly::operator - (Poly &rhs) {
    int cmax = max_exp;
    if(cmax < rhs.Get_max())
        cmax = rhs.Get_max();
    int ctmp[cmax];
    for(int i = 0 ; i < cmax; i++)
        ctmp[i] = 0;
    for(int i = 0 ; i < max_exp; i++)
        ctmp[i] = coefficient[i];
    for(int i = 0 ; i < rhs.Get_max(); i++)
        ctmp[i] -= rhs.Get_ico(i);
    Poly ptmp(cmax, ctmp);
    return ptmp;
}
Poly Poly::operator * (Poly &rhs) {
    int cmax = max_exp + rhs.Get_max() - 1;
    int ctmp[cmax];
    for(int i = 0; i < cmax; i++)
        ctmp[i] = 0;
    for(int i = 0 ; i < max_exp; i++)
        for(int j = 0 ; j < rhs.Get_max(); j++)
            ctmp[i + j] += coefficient[i] * rhs.Get_ico(j);
    Poly ptmp(cmax, ctmp);
    return ptmp;
}

int main(int argc, char **argv) {
    char oper = argv[argc-1][0];
    int x, y;
    x = atoi(argv[1]);
    int cx[x];
    for(int i = 0; i < x; i++)
        cx[i] = atoi(argv[ 2 + i ]);
    Poly px(x, cx);
    y = atoi(argv[2 + x]);
    int cy[y];
    for(int i = 0; i < y; i++)
        cy[i] = atoi(argv[ x+3+i ]);
    Poly py(y, cy);

    if(oper == '+') {
        Poly pz= px + py;
        pz.Print_poly();
        return 0;
    }
    else if(oper == '-') {
        Poly pz = px - py;
        pz.Print_poly();
        return 0;
    }
    else if(oper == 'x') {
        Poly pz = px * py;
        pz.Print_poly();
        return 0;
    }

    return 0;
}
