#include <iostream>
#include "assert.h"
using namespace std;
class Vector{
private:
    int *arr = {nullptr};
    int capacity{};
    int size {0};
public:
    Vector(int size) : size(size){
        if(size < 0)
            size = 1;
        capacity = size + 10;
        arr = new int[capacity];
    }
    ~Vector(){
        delete[] arr;
        arr = nullptr;
    }
    int get_size(){
        return size;
    }
    int get(int idx){
        assert(idx >= 0 && idx < size);
        return arr[idx];
    }
    void set(int idx,int val){
        assert(idx >= 0 && idx < size);
        arr[idx] = val;
    }
    void print(){
        for(int i =0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
//    void insert(int val,int idx){
//        int *temp = new int [size - idx + 1];
//        temp[0] = val;
//        for(int i = idx;i<size;i++){
//            temp[i - idx + 1] = arr[i];
//        }
//        this->push_back(-1);
//        // 0 1 2 3 4 5
//        for(int i = idx;i<size;i++){
//            arr[i] = temp[i - idx];
//        }
//    }

    void insert(int idx, int value) {
        assert(0 <= idx && idx < size);

        // we can't add any more
        if (size == capacity)
            expand_capacity();

        // Shift all the data to right first

        for(int p = size-1; p >= idx; --p)
            arr[p+1] = arr[p];

        arr[idx] = value;
        ++size;

        // Common mistake to iterate from begin to end
        // the whole array right array will be arr[idx]
        //for (int p = idx; p < size; ++p)
    }
    int pop(int idx){
        assert(0 <= idx && idx < size);
        int val = arr[idx];
        for(int i =idx;i<size-1;i++){
            arr[i] = arr[i+1];
        }
        size--;
        // 1 2 3 4 5
        return val;


    }
    int find(int value){
        for(int i =0;i<size;i++){
            if(arr[i] == value)
                return i;
        }
        return -1;
    }
    int find_transposition(int target){
        int pos = find(target);
        if(pos != -1){
            if(pos >= 1) {
                int temp = arr[pos - 1];
                arr[pos - 1] = arr[pos];
                arr[pos] = temp;
            }
            pos--;
        }
        return pos;
    }
    void expand_capacity(){
        capacity *= 2;
        //cout << "expanded\n";
        int *temp = new int [capacity];
        for(int i = 0;i<size;i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    void push_back(int val){

        if(size == capacity){
            expand_capacity();
        }
        arr[size++] = val;

    }
    void right_rotate(int time){
        for(int j = 0;j<(time % size);j++) {
            int last = arr[size - 1];
            for (int i = size - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = last;
        }
    }
    void left_rotate(int time) {
        for (int j = 0; j < (time % size); j++) {
            int first = arr[0];
            for (int i = 0; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[size - 1] = first;
        }
    }
};
int main() {
    Vector v(5);
    for(int i =0;i<5;i++){
        v.set(i,(i+1)*10);
    }

    return 0;
}
