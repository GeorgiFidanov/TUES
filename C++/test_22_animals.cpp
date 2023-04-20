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

    void set_legs(){
        this -> legs = legs;
    }

    string get_name(){
        cout << "get_name called" << endl;
        return name;
    }

    void set_name(){
        this -> name = name;
    }

};



int main()
{
    Animal cat("chamber", 60);
    cat.get_legs();
    cat.set_legs();
    cat.get_name();
  //  cat.set_name();
    cout << cat.get_name() << endl;

    return 0;
}
