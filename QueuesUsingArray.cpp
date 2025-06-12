#include <iostream>
using namespace std;

class Queue{
    private:
       static const int max = 5;
       int FRONT, REAR;
       int queue_array[5]; 
    public:
        Queue(){
            FRONT = -1;
            REAR = -1;
        }
};