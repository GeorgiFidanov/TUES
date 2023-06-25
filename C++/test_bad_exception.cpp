#include <iostream>

using namespace std;

class Illegal_price_Exception : public exception{
    private:
        string message;

    public:
        Illegal_price_Exception(const string& message) : message(message) {}

        const string& getMessage() const{
            return message;
        }

        void setMessage(const string& messageToSet){
            this->message = messageToSet;
        }
};

class Product{
    public:
        std::string name;
        unsigned int count;
        double price;

        void check_price(){
            if(price < 0){
                throw Illegal_price_Exception("Illegal price; price is less than zero");
            }
        }
};

int main(){
    cout << "Hello world!" << endl;
    return 0;
}
