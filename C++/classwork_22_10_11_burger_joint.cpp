#include <iostream>
using namespace std;

class Sauce {
    public:
        int amount;
        string name;
        string color;
    Sauce(int amount, string name): name(name){
        this->amount = amount;
    }

    Sauce() {}

};

class Burger {

protected:
    float weight;
    int size;
    float price;
    Sauce *sauce;
    friend void print(Burger& d);

public:
    Burger(int size, float price, float weight){
        this-> weight = weight;
        this->price = price;
        this->size = size;
    }

    virtual void eat(){
        cout << "Burger was eaten. It had " << sauce->name << " sauce" << endl;
    }

    void addSauce(Sauce *sauce){
        this->sauce = sauce;
    }

    int getSize() const { // const ensures that we can't modify class properties
        return size;
    }
     
     float getWeight() const {
        return weight;
    }

    virtual float getPrize() const {
        return price * (weight/2);
    }
   

    const Sauce& getSauce() const { // Get a reference to the sauce in the doner for reading only, instead of returning a Sauce copy
        return *sauce;
    }

    int operator +(int g){ // allows using operator '+' to add Doner and int => doner1 + 10; doner1 + 16
        return size + g;
    } 
    
    int operator [](string j){ // allows index operator [] to be used on doner with string argument => doner1["sauce1"]; doner1["sauce2"];
        return size;
    }

     int operator ==(int j){ // allows index operator [] to be used on doner with string argument => doner1["sauce1"]; doner1["sauce2"];
        return size;
    }


};

void print(Burger& d){
    
};

class Hotdog : public Burger{
    public:
     Hotdog(int size, float price, float weight){
        this->weight = weight;
        this->price = price;
        this->size = size;
    }

    void eat(){
        cout << "Weenie eaten. It had " << sauce->name << " sauce" << endl;
    }

    float getPrize() const {
        if(sauce == NULL){
        return price * (weight/2)* sauce->amount*0.2;
        }else{
            return price * (weight/2);
        }
    }
}



int main() {

    Sauce sauce = Sauce(5, "white");
    Burger borgor = Burger(0.3, 10, 6.4);
    borgor.addSauce(*sauce);
    cout << borgor.getSauce().name << endl;

    //dn1.getSauce().amount = 10; -- doesn't compile!! getSauce returns a readonly reference. No modification allowed.
    borgor.eat();
    cout << borgor.getSauce().name << endl;
    cout << borgor.getSauce().amount << endl;
    cout << borgor + 5 << endl;

}