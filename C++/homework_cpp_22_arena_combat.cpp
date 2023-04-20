#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Character
{

protected:
    string name;
    float health;
    float defense;

public:
    Character(string name, float health, float defense){
        this -> name = name;
        this -> health = health;
        this -> defense = defense;
    }
       
    Character(const Character& other){
        this -> name = other.name;
        this -> health = other.health >= 0 ? other.defense : 1;
        this -> defense = other.defense >= 0 ? other.defense : 1;
    }

    Character& operator= (const Character& other){
        name = other.name;
        health = other.health >= 0 ? other.defense : 1;
        defense = other.defense >= 0 ? other.defense : 1;
        return *this;
    }

    const string& getName(){
        return name;
    }

    void setName(const string& name){
        this -> name = name;
    }

    float getHealth(){
        return health;
    }

    void setHealth(const float health){
        this -> health = health;
    }

    float getDefense() {
        return defense;
    }

    void setDefense(const float defense){
        this -> defense = defense;
    }
};

class Enemy : public Character
{
private:
    float damage;

public:
    Enemy(const string& name, float health, float defense, float damage) : Character(name, health, defense){
        this -> damage = damage;
    }

    float getDamage(){
        return damage;
    };
    
    void setDamage(const float damage){
        this -> damage = damage;
    }
};

class Ability
{
private:
    string name;
    float damage;
    
public:
    Ability(const string& name, const float damage);
    
    float getDamage(){
        return this -> damage;
    }
    
    void setDamage(const float damage){
        this -> damage = damage;
    }
    
    const string& getName(){
        return this -> name;
    }
    
    void setName(const string& name){
        this -> name = name;
    }
};

class Player : public Character{

public:
    Player(const string& name, float health, float defense, const vector<Ability>& abilities) : Character(name, health, defense) {
        this -> abilities = abilities;
    };

    Player& addAbility(const Ability& ability){
        this -> abilities.push_back(ability);
        return *this;
    };
    
    const vector<Ability>& getAbilities()const{
        return this -> abilities;
    };

private:
    vector<Ability> abilities;
};

class PlayerHelper
{
public:
    static float getTotalPlayerDamage(const Player& player){
        float total_abil = 0.00;
        vector <Ability> aBility = player.getAbilities();
        for(int i = 0; aBility.size() > i; i++){
            total_abil += aBility[i].getDamage();
        }
    }
};

class Arena
{
public:
    static int currentEnemyIndex;

    static bool fight(Player& player, vector<Enemy>& enemies){
        cout<<";[";
    }
};

int Arena::currentEnemyIndex = 0;


int main()
{
    ifstream file;
    file.open("Input.txt");
    string word;

    getline(file, word);
    cout<<word;

    string line; 
    string playerName;
    float playerHealth, playerDefence;
   stringstream word_ss(line);

    word_ss>>playerName>>playerHealth>>playerDefence;
    cout<<";[";
    return 0;
}
