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
        void insert(){
            int num;
            cout << "Enter a number : ";
            cin >> num;
            cout << endl;

            //1. cek apakah antrian penuh
            if((FRONT == 0 && REAR == max - 1) || (FRONT = REAR + 1)){
                cout << "\nQueue overlow\n";//1.a
                return; //1.b
            }