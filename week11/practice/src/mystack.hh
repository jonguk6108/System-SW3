#include "base.hh"

class MyStack : public BaseArray{
public:
    MyStack(int _capacity) : BaseArray(_capacity), top(0) {}

public:
    void push(int _val) {
        // TODO: Fill Your Code Here
        if(top >= getCapacity()) {
            std::cout << "Stack is full.. \n";
            exit(1);
        }
        insert(top, _val);
        top++;
    }

    int pop() {
        if(top < 0) {
            std::cout << "Stack is empty.. \n";
            exit(1);
        }
        top--;
        return get(top);
    }

    int getSize() override{return top;}
    void printLoc() override{std::cout << "top: " << top << std::endl;}
    
private:
    int top;
};
