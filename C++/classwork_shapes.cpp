#include <iostream>

using namespace std;

class Triangle{
private:
    int a, b, c;
    int ha;

public:
    Triangle(){
        this->a = 0;
        this->b = 0;
        this->c = 0;
        this->ha = 0;
    }

    //copy constructor
    Triangle(const Triangle& other){
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;
        this->ha = other.ha;
    }

    // getter
    void getTriangle(){
        cout << this->a << ", " << this->b << ", " << this->c << ", " << this->ha << endl;
    }

    // setter
    void setTriangle(int a, int b, int c, int ha){
        this->a = a;
        this->b = b;
        this->c = c;
        this->ha = ha;
    }

    // get area
    int getAreaTriangle(){
        return (this->a * this->ha) / 2;
    }
};

class Rectangle{
private:
    int a;

public:
    Rectangle(){
        this->a = 0;
    }
    
    // copy constructor
    Rectangle(const Rectangle& other){
        this->a = other.a;
    }

    // getter
    void getRectangle(){
        cout << this->a << endl;
    }

    // setter
    void setRectangle(int a){
        this->a = a;
    }
    
    // get area
    int getAreaRectangle(){
        return this->a * this->a;
    }


};

int main(int argc, char** argv){
    Triangle exp;
    cout << "Triangle sides: ";
    exp.setTriangle(3,4,5,4);
    exp.getTriangle();
    cout << "Triangle area = " << exp.getAreaTriangle(3, 4, 4);
    cout << endl;
    //Triangle example

    Rectangle r;
    cout << "Rectangle sides: ";
    r.setRectangle(5);
    r.getRectangle();
    cout << "Rectangle area = " << r.getAreaRectangle(5); 
    cout << endl;
    //Rectangle example

    return 0;
   
}