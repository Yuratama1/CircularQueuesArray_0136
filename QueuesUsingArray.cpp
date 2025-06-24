/** 
 * @mainpage Documentation Circular Queues
 * 
 * @section Introduction
 * Project ini merupakan Project strucktur data
 * menggunakan strucktur data queue dengan pendekatan circular arrays.
 * 
 * @section Operations
 * Project ini memiliki beberapa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 
 * @section Cara pengunaan
 * Berikut beberapa menu yang bisa digunakan:
 * 1. Insert Queue
 * 2. Delete Queue
 * 3. Display
 * 4. Exit
 * 
 * @author Profil
 * - Nama  : Yuratama Fadhilah Nugroho
 * - Nim   : 20240140136
 * - Kelas : C
 * 
 * @brief
 * @version 1.0
 * @date 2025-06-24
 * 
 * @copyright y.fadhilah.ft24@umy.ac.id (c) 2025
 * 
 * 
*/
#include <iostream>
using namespace std;
/**
 * @class Queue
 * @brief class ini untuk operasi lengkap queue
 * 
 * 
 */
class Queue{
    private:
       static const int max = 5;///< variable private max untuk menyimpan ukuran maximum antrian
       int FRONT;///< variable private front untuk menyimpan posisi depan antrian
       int REAR;///< variable private rear untuk menyimpan posisi belakang antrian
       int queue_array[5]; ///< variable private queue_array untuk menyimpan elemen antrian
    public:
        /**
         * @brief Constructor a new queue object
         * set default queue null
         * with front = -1 and rear = -1
         */
        Queue(){
            FRONT = -1;
            REAR = -1;
        }
        /**
         * @brief method untuk memasukkan data dalam antrian
         * data dimasukkan dalam variable queue_array.
         */
        void insert(){
            int num;///< variable num untuk menyimpan nilai
            cout << "Enter a number : ";
            cin >> num;
            cout << endl;

            //1. cek apakah antrian penuh
            if((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)){
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
        /**
         * @brief method untuk menghapus data dalam antrian
         * data dihapuskan dari dalam variable queue_array
         */
        void remove(){
            //cek apakah antrian kosong
            if (FRONT == - 1){
                cout << "Queue underflow\n";
                return;
            }
            cout << "\nThe element deletd from the queue is :" << queue_array[FRONT] << "\n";
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
        /**
         * @brief method untuk menampilkan data dalam atrian
         * data ditampilkan dari dalam variable queue_array
         */
        void display(){
            int FRONT_position = FRONT;///< variable FRONT_position untuk menandakan posisi element pertama pada variable front
            int REAR_position = REAR;///< variable REAR_position untuk menandakan posisi element terakhir pada variable rear

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
            else{
                //jika front_position > rear_position, interaksi dari front hingga akhir array
                while(FRONT_position <= max - 1){
                    cout << queue_array[FRONT_position] << " ";
                    FRONT_position++;
                }
                FRONT_position = 0;

                while(FRONT_position <= REAR_position){
                    cout << queue_array[FRONT_position] << " ";
                    FRONT_position++;
                }
                cout << endl;
            }
        }
};
/**
 * @brief method utama untuk menjalankan program
 * 
 * @return int
 */
int main(){
    Queue q;///< objek untuk menggunakan member yang ada dalam class queue
    char ch;///< variable ch untuk menyimpan pilihan pada menu yang di berikan

    while(true){
        try{
            cout << "Menu" << endl;
            cout << "1. Implement insert opration" << endl;
            cout << "2. Implement delete opration" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice" << endl;
            cin >> ch;
            cout << endl;

            switch(ch){
                case '1':{
                    q.insert();
                    break;
                }
                case '2':{
                    q.remove();
                    break;
                }
                case '3':{
                    q.display();
                    break;
                }
                case '4':{
                    return 0;
                }
                default:{
                    cout << "Invalid option" << endl;
                    break;
                }
            }
        }
        catch (exception &e){
            cout << "Check for the values entered." << endl;
        }
    }
}