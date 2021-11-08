#ifndef __BASE_HH__
#define __BASE_HH__

#include <iostream>

// Parent Class(called as Base Claas)
class BaseArray {
public:
    BaseArray(int _capacity=100) : capacity(_capacity), mem(new int[_capacity]){}
    ~BaseArray() {
        delete[] mem;
    }

public:
    void insert(int _index, int _val) { mem[_index]=_val; }
    int get(int _index) { return mem[_index]; }
    int getCapacity() { return capacity; }

    virtual int getSize() = 0;
    virtual void printLoc() = 0; //pure virtual function
    virtual void enqueue(int _val){};
    virtual int dequeue(){return -1;};
    virtual void push(int _val){};
    virtual int pop(){return -1};
  
private:
    int capacity;       // size of array
    int *mem;           // memory pointer
};

#endif
