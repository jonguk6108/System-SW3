#include<iostream>
class Vector{
    public:
        Vector(int sz);
        ~Vector();
        void push_back(int val);
        int get_back();
        int get_value(int idx);
        void remove(int idx);       
        void swap(int idx1, int idx2);
        void print();
    private:
        int* value;                                   
        int capacity;               
        int back;                   
};
Vector::Vector(int sz) : value(new int[sz]), capacity(sz), back(-1) {}
Vector::~Vector(){delete[] value;}
int Vector::get_back(){return back;}
int Vector::get_value(int idx){return value[idx];}
void Vector::push_back(int val){
    if(back<capacity-1) back++;
    value[back] = val;
}
void Vector::remove(int idx){
    for(int i=idx;i<back;i++) value[i] = value[i+1];
    back--;
}
void Vector::swap(int idx1, int idx2){
    int temp;
    temp = value[idx1];
    value[idx1] = value[idx2];
    value[idx2] = temp;
}
void Vector::print(){
    for(int i=0;i<=back;i++) std::cout << value[i] << " "; std::cout << std::endl;
}

void sort(Vector& v){
    for(int i=v.get_back();i>0;i--){
        for(int j=0;j<i;j++){
            if(v.get_value(j)<v.get_value(j+1)){
                v.swap(j,j+1);
            }
        }    
    }
}

int main(){
    Vector v(10);
    for(int i=0;i<13;i++) v.push_back(i);
    v.print();
    v.remove(3);
    v.print();
    sort(v);
    v.print();
}
