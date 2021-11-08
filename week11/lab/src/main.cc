#include <vector>
#include <string>

#include "circular_queue.hh"

#define DEQUEUE 1
#define ENQUEUE 0

int main() {

    int N;          // The size of queue
    int K;          // The number of commands
    std::cin >> N >> K;
    std::vector<std::string> output_buffer;

    BaseArray* ba = new CircularQueue(N);
    ;
    for(int i=0; i<K; i++){
        int cmd;
        std::cin >> cmd;
        
        switch(cmd){
            case ENQUEUE:
                int input;
                std::cin >> input;
                if(ba->isFull()){
                    output_buffer.push_back("Full: Enqueue Fail");
                }
               else{
                    output_buffer.push_back("Enqueue Success");
                    ba->enqueue(input);
                }
                break;

            case DEQUEUE:
                if(ba->isEmpty()){
                    output_buffer.push_back("Empty: Dequeue Fail");
                }
                else{  
                    int deque_val = ba->dequeue();
                    output_buffer.push_back(std::to_string(deque_val));
                }
                break;

            default:
                std::cout<<"Wrong Command!!" << std::endl;
                exit(1);
                break;
        }
    }
    
    for(auto it=output_buffer.begin(); it != output_buffer.end(); it++)
        std::cout << *it << std::endl;
}




