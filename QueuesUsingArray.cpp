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
            //2. cek apakah antrian kosong
            if (FRONT == -1){
                FRONT = 0; //2.a
                REAR = 0; //2.b
            }
            else{
                //jika rear brada di posisi terakhir array, kembali ke awal array
                if(REAR == max - 1)
                    REAR = 0;
                else
                    REAR = REAR + 1;
            }
            queue_array[REAR] = num;
        }
        void remove(){
            //cek apakah antrian kosong
            if (FRONT == - 1){
                cout << "Queue underflow\n";
                return;
            }
            cout << "\nThe element deled from the queue isi :" << queue_array[FRONT] << "\n";
            //cek apakah antrian hanya memeilki satu elemen
            if(FRONT == REAR){
                FRONT = -1;
                REAR = -1;
            }
            else{
                //jika element yg dihapus berada di posisi terakhir array, kembali ke awal array
                if(FRONT == max -1)
                    FRONT = 0;
                else
                    FRONT = FRONT + 1;
            }
        }
        
        void display(){
            int FRONT_position = FRONT;
            int REAR_position = REAR;

            //cek apakah antrian kosong
            if (FRONT == -1){
                cout << "Queue is empty\n";
                return;
            }
            cout << "\nElement is the queue are ...\n";

            //jika front_position <= REAR_position, iteraksi dari front hingga rear
            if(FRONT_position <= REAR_position){
                while(FRONT_position <= REAR_position){
                    cout << queue_array[FRONT_position] << " ";
                    FRONT_position++;
                }
                cout << endl;
            }
            