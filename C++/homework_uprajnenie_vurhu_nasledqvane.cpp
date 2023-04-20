#include <iostream>
#include <vector>

using namespace std;

class Animal {
private:
    bool isAnimal; 
protected: 
    int age;

public:

    Animal(int age = 0)
    {
        isAnimal = true;
        this->age = age;
        cout << "animal constructor called" << endl;
    }

    int getAge()
    {
        cout << "getAge called" << endl;
        return this->age; 
    }

    bool getIsAnimal() 
    {
        return this->isAnimal;
    }
};

class Cow : public Animal {
protected:
    bool isMale;
public:
    Cow(int age, bool isMale) : Animal(age)
    {
        this->isMale = isMale;
        cout << "cow constructor called" << endl;
    }

    bool getMale()
    {
        cout << "Cow::isMale called" << endl;
        return this->isMale;
    }
};

class Cat : public Animal {
private:
	int meowPower;
	bool isMeowing;

public:
	Cat(int age, int _mPower, bool _isMeowing) : Animal(age), meowPower(_mPower), isMeowing(_isMeowing) {}

	int getMeowPower() {
		return meowPower;
	}

	bool isCatMeowing() {
		return isMeowing;
	}
};

class Dog : public Animal {
private:
	bool isBarking;
	int ageInDogYears;

public:
	Dog(int age, bool _isBarking) : Animal(age), isBarking(_isBarking) {
		ageInDogYears = age * 7;
	}

	int getAgeInDogYears() {
		return ageInDogYears;
	}

	bool isDogBarking() {
		return isBarking;
	}
};

float GetAverageAge(vector<Animal*> animals) {
	float sum = 0;

	for(Animal *i : animals) {
		sum += (float)i->getAge();
	}

	return sum / (float)animals.size();
}

int main() {
	Cat cat(6, 20, false);
	Dog dog(10, true);
	Cow cow(9, false);

	vector<Animal*> _animals = {&cat, &dog, &cow};

	cout << "Dog age in dog years: " << dog.getAgeInDogYears() << endl;
	cout << "Average age: " << GetAverageAge(_animals) << endl;

	return 0;
}