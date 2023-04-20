#include <iostream>
using namespace std;

//========VECTOR=============
class Vector{
private:
    int* array;
    int size;
    int capacity;
public:
    int GetSize(){
        return this->size;
    }
    int GetCapacity(){
        return this->capacity;  
    }
//========END VECTOR==========

//=========FUNCTIONS==========
    Vector(int capacityToSet = 7){
        this->size = 0;
        this->capacity = capacityToSet;
        this->array = new int[this->capacity];
        
        for(int i = 0; i < this->capacity; i++){
            this->array[i] = 0;
        }
    }
    
    ~Vector(){
        delete [] this->array;
        this->array = nullptr;
        this->size = 0;
        this->capacity = 0;
    }
    
    void print(){
        for(int i = 0; i < this->size; i++){
            cout << this->array[i] << " ";
        }
        cout << endl;
}
//=====HW=======
    Vector& push_back(int value){
        if(this->capacity == this->size){
            this->capacity *= 2;
            int* temp = new int[this->capacity];
            
            for(int i = 0; i < this->size; i++){
                temp[i] = this->array[i];
            }
            delete[] this->array;
            this->array = temp;
        }
        this->array[this->size] = value;
        this->size++;
        return *this;
    }
    
    Vector& pop_back(){
        this->size--;
        return *this;
    }
    
    Vector& remove_at(int index){
        for(int i = index; i < this->size -1; i++){
            if(i >= index){
                this->array[i] = this->array[i+1];
            }
        }
        this->size--;
        return *this;
    }
};
//===END HW=====

//=========END FUNCTIONS======

int main(int argc, char** argv) {
    Vector v(3);
    int previousSize = v.GetSize();
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);
    v.print();
    
    cout << "previous size: " << previousSize << "  size after push back: " << v.GetSize() << endl;
    
    previousSize = v.GetSize();
    v.print();
    v.remove_at(0);
    cout << "previous size: " << previousSize << " size after push back: " << v.GetSize() << endl;
    v.print();
    
    return 0;
}