#include <iostream>
#include <vector>

using namespace std;

class Player{
protected:
	int hp;
	int armor;
	int attack_power;
	int energy;
	int base_energy;
	int max_hp;
	vector<string> commands;

public:
	Player(int _hp, int _armor, int _attack_power, int _energy){
		hp = _hp;
		armor = _armor;
		attack_power = _attack_power;
		energy = _energy;
		base_energy = _energy;
		max_hp = _hp;
	}

	int takeAction(string cmd){
		if(!count(commands.begin(), commands.end(), cmd)){
			return -2;
		}
		switch(cmd){
			case "move":
				return energy > 1;
				break;
			case "sepuko":
				hp = 0;
				break;
			case "heal":
				hp += 10;
				hp = hp > max_hp ? max_hp : hp;
				break;
			case "attack":
				if(energy > 1){
					return attack_power;
				}else{
					return -1;
				}
				break;
			case "swap":
				return energy > 2;
			case "resurrect":
				return energy > 3;
			case "counter":
				if(energy > 3){
					return attack_power;
				}else{
					return -1;
				}
			case "fireball":
				return energy > 2;
		}
	}
	
	void rest(){
		energy = _base_energy;
	}

	int getHP(){
		return hp;
	}

	void isDead(){
		return hp > 0;
	}
};

class Mage: public Player{
public:
	Mage(int _hp = 100, int _armor = 5, int _attack_damage = 30, int _energy = 3) : Player(_hp, _armor, _attack_damage, _energy){
	commands.insert(commands.end(), {"sepuko", "heal", "attack", "fireball", "move"});
	}

	int P(){
		cout << hp;
		return 1;
	}
};

class Necromancer : public Player{
public:
	Necromancer(int _hp = 120, int _armor = 10, int _attack_power = 50, int _energy = 5) :Player(_hp, _armor, _attack_damage, _energy){
		commands.insert(commands.end(), {"sepuko", "attack", "fireball", "resurrect", "swap"});
	}
};

class Warrior : public Player{
public:
	Warrior(int _hp = 120, int _armor = 30, int _attack_power = 40, int _energy = 3) :Player(_hp, _armor, _attack_damage, _energy){
		commands.insert(commands.end(), {"sepuko", "attack", "move"});
	}
};

class Swordsman : public Player{
public:
	Necromancer(int _hp = 200, int _armor = 30, int _attack_power = 40, int _energy = 5) :Player(_hp, _armor, _attack_damage, _energy){
		commands.insert(commands.end(), {"sepuko", "attack", "move", "counter"});
	}
};

class Skeleton : public Player{
public:
	Skeleton(int _hp = 20, int _armor = 6, int _attack_power = 20, int _energy = 99999999) :Player(_hp, _armor, _attack_damage, _energy){
		commands.insert(commands.end(), {"attack"});
	}
};

class Zombie : public Player{
public:
	Zombie(int _hp = 30, int _armor = 8, int _attack_power = 10, int _energy = 99999999) :Player(_hp, _armor, _attack_damage, _energy){
		commands.insert(commands.end(), {"attack"});
	}
};

class GameField{
private:
	vector<Player> heroes;
	vector<Player> monsters;
	vector<Player> graveyard;
};

int main(){
	Mage mage = Mage();
	mage.P();

}
