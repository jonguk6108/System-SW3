#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {data.clear();}

void PriorityQueue::sort() {

    for (size_t i=0; i<data.size(); i++) {
        for (size_t j=0; j<data.size()-i-1; j++) {
            if (is_ahead(*this, j+1, j)) {
                double temp = data.at(j);

                data.at(j) = data.at(j+1);
                data.at(j+1) = temp;
            }
        }
    }
}

void PriorityQueue::push(double element) {
    data.push_back(element);
    sort();
}

double PriorityQueue::front() {return data.front();}

double PriorityQueue::pop() {
    std::vector<double>::iterator it = data.begin();

    double d = data.front();
    data.erase(it);

    return d;
}
