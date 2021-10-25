#include "PriorityQueue.h"

bool is_ahead(PriorityQueue queue, size_t idx1, size_t idx2) {
    return ( queue.data.at(idx1) < queue.data.at(idx2) );
    //TODO : The smaller one is ahead.
}
