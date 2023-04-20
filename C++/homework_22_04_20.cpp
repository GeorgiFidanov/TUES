#include <iostream>
//#include <exception>
/*
class Illegal_price_Exception : public std::exception{
public:
    Illegal_price_Exception(const std::string& message) : message(message) {}

    const std::string& getMessage() const{
        return message;
    }

    void setMessage(const std::string& messageToSet)
    {
        this->message = messageToSet;
    }

private:
    std::string message;
};*/
class Product{

protected:

public:
    std::string name;
    unsigned int count;
    double price;
    
    Product(){
        std::cout << "Constructor \n";
    }
    Product(std::string name, unsigned int count, double price){
        this->name = name;
        this->count = count;
        this->price = price;
    }

    ~Product(){
        std::cout << "Destructor\n";
    }

    void get_info(){
        std::cout << "Product name: " << name << std::endl;
        std::cout << "Product count: " << count << std::endl;
        std::cout << "Product price: " << price << std::endl;
    }

    void check(double price){
    if(price < 0){
        throw "Illegal price; price is less than zero";
    };
    };
    //Конструктор по подразбиране;
    //Конструктор с параметри;
    //Копиращ конструктор;
    //Предефиниран оператор=;
    //Getter-и за всички полета;
    //Setter-и за цена и количество;
    //Входните данни на конструктора с параметри трябва да бъдат валидирани. 
    //За да хванете, че е имало невалидни данни сложете стойност на цената -1;



};


class Property{

public:
    std::string name;
    double rent;
    std::string type_of_renting;
    bool supermarket, pharmacy, non_stop, other;
    //Конструктор с параметри;
    //Копиращ конструктор;
    //Предефиниран оператор=;
    //Getter-и за всички полета, освен за наема;
    //Метод, който да изчислява наема в зависимост от типа на имота;
        //supermarket - базов наем + 0.4*базов наем;
        //pharmacy - базов наем + 0.3*базов наем;
        //non-stop - базов наем + 0.2*базов наем;
        //other - базов наем;
    //Входните данни на конструктора с параметри трябва да бъдат валидирани.
    //За да хванете, че е имало невалидни данни сложете стойност на наема -1;

};


//class Store(Property){

//public:
  //  std::string name;
    //Списък от продукти, които се продават в магазина (динамичен масив);
 



//};
/*using namespace std;
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
*/
int main()
{
    Product test("mamba", 2, 2.50);

    menu:
    int ans;
    char* answer;
   std::cout <<"Please select an answer: (answer must be chosen between 0 and 7)" << std::endl;
    scanf("%d", &ans);

    if(ans == 0){
       std::cout <<("Goodbye!");
        return 0;
    }
    else if(ans == 1){ //add product

       std::cout <<("Please, enter new item's specs: name, count, price\n")<< std::endl;

       std::cout <<("-----------------------------------")<< std::endl;

       std::cout <<("\nGo back to main menu? ")<< std::endl;
        scanf("%s", answer);
        if(answer=="Yes"){           
            goto menu;
        }else{ std::cout<<("Goodbye!")<< std::endl;}
    }
    else if(ans == 2){ //Check product quantity
        
       std::cout <<("You have selected the Check product quantity option.\nPlease search a product by its name: ")<< std::endl;
        scanf("%s",&answer);
        if(answer == /*Product.name*/){
       std::cout <<("%s - %d\n",/*Product.name*/, /*Product.count*/)<< std::endl;
       std::cout <<("\nGo back to main menu? ");
        scanf("%s", answer);
        if(answer=="Yes"){           
            goto menu;
    return 0;
    
    
    
    
    
    
    /*
    unique_ptr ptr(5);
    ptr.unique_ptr_get();
    cout << ptr.unique_ptr_get()

     << endl;
     */

    //for(int i=5; i<1; i--){
        bool supermarket = 1;
        bool pharmacy = 2;
        bool non_stop = 3;
        bool other = 4; 

        if (Property.rent<=0){
            std::cout<<"too good price";
        }
    //}

    return 0;
}
