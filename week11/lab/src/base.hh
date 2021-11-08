#ifndef __BASE_HH__
#define __BASE_HH__

#include <iostream>

// Parent Class(called as Base Claas)
class BaseArray {
public:
    BaseArray(int _capacity=5) : capacity(_capacity), mem(new int[_capacity]){}
    virtual ~BaseArray() { delete[] mem; } //TODO: Fix this destructor

public:
    void insert(int _index, int _val) { mem[_index]=_val; }
    int get(int _index) { return mem[_index]; }
    int getCapacity() { return capacity; }

    // TODO: Fill virtual member functions

    virtual void enqueue(int n){};
    virtual int dequeue(){return -1;};
    virtual bool isEmpty(){return false;};
    virtual bool isFull(){return false;};

private:
    int capacity;       
    int *mem;           
};

#endif
