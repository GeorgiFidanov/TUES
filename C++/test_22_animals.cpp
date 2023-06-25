#include <iostream>

using namespace std;

class Animal{

protected:
    string name;
    int legs;

public:

    Animal(string name, int legs){
        this -> name = name;
        this -> legs = legs;
    }
    Animal(const Animal& other){
        this -> legs = other.legs;
        this -> name = other.name;
    }

    int get_legs(){
        cout << "get_legs called" << endl;
        return legs;
    }

    void set_legs(int legs){
        this -> legs = legs;
    }

    string get_name(){
        cout << "get_name called" << endl;
        return name;
    }

    void set_name(string name){
        this -> name = name;
    }

};



int main()
{
    int a = 4;
    Animal cat("chamber", 60);
    cat.get_legs();
    cat.set_legs(a);
    cat.get_name();
    cat.set_name("Ivan");
    cout << cat.get_name() << endl;

    return 0;
}
