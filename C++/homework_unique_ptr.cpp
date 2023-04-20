#include <iostream>

using namespace std;

class unique_ptr{
    private:
        int *ptr;

    public:
        unique_ptr(int value){
            this->ptr = &value;
        }
        ~unique_ptr(){
            this->ptr = nullptr;
        }

        unique_ptr_get(){
            return *this->ptr;
        }

};

int main()
{
    unique_ptr ptr(5);
    ptr.unique_ptr_get();
    cout << ptr.unique_ptr_get()

     << endl;
    return 0;
}
