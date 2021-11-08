#include "circular_queue.hh"

bool CircularQueue::isEmpty() {
    if(front == -1)
        return true;
    else
        return false;
}

bool CircularQueue::isFull() {
    if(front == 0 && rear == getCapacity() - 1)
        return true;
    if(front == rear +1)
        return true;
    return false;
}

void CircularQueue::enqueue(int n){
    if(isFull()) {
        std::cout << "Queue is full";
    }
    else {
        if(front == -1) front = 0;
        rear = (rear+1)%getCapacity();
        insert(rear, n);
    }
}

int CircularQueue::dequeue(){
    int element;
    if( isEmpty() ) {
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }
    else {
        element = get(front);
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % getCapacity();
        }
    }
    return element;
}
