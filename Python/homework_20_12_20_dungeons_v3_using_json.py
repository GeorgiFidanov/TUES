import random
import json
import sys


# noinspection PyPep8Naming,PyShadowingNames
class Entity:
    def __init__(self, name, health, maxHealth, weapon):
        self.name = name
        self.health = health
        self.maxHealth = maxHealth
        self.weapon = weapon

    def is_alive(self):
        return self.health > 0

    def get_health(self, hp):
        if self.is_alive():
            if hp > self.maxHealth:
                self.health += hp
            else:
                self.health = self.maxHealth
            return True
        else:
            return False

    def take_damage(self, dmg):
        if dmg > self.health:
            self.health = 0
        else:
            self.health -= dmg

    def has_weapon(self):
        return bool(self.weapon)

    def equip_weapon(self, _weapon):
        self.weapon = _weapon

    def attack(self):
        if not bool(self.weapon):
            return 0
        return self.weapon.damage * 2 if self.weapon.critical_hit() else self.weapon.damage


# noinspection PyPep8Naming,PyShadowingNames
class Hero(Entity):
    def __init__(self, name, health, maxHealth, nickname, weapon=None):
        super().__init__(name, health, maxHealth, weapon)
        self.nickname = nickname
        print("{}: Ready for adventures".format(self.name))

    def __str__(self):
        return("Name: {}, Health: {}, maxHealth: {}, nickname: {}"
               .format(self.name, self.health, self.maxHealth, self.nickname))


# noinspection PyPep8Naming,PyShadowingNames
class Orc(Entity):
    def __init__(self, name, health, maxHealth, berserk_factor, weapon=None):
        super().__init__(name, health, maxHealth, weapon)
        self.berserk_factor = berserk_factor
        print("{}: Prepare for trouble, make it double".format(self.name))

    def __str__(self):
        return("Name: {}, Health: {}, maxHealth: {}, berserk factor: {}"
               .format(self.name, self.health, self.maxHealth, self.berserk_factor))


class Weapon:
    def __init__(self, name, damage, critical_strike_percent, chance=1):
        self.name = name
        self.damage = damage
        self.chance = chance
        self.critical_strike_percent = critical_strike_percent

    def critical_hit(self):
        random_chance = random.uniform(0, 1)
        if random_chance <= self.chance:
            self.damage = self.damage * 2
            return True
        else:
            return False

    def __str__(self):
        return ("Name: {}, Damage: {}, Critical strike percent: {}, Chance: {}, Critical hit: {}"
                .format(self.name, self.damage, self.critical_strike_percent, self.chance, self.critical_hit()))


if __name__ == '__main__':

    filename = ""  # data.json
    weapons = []
    heroes = []
    orcs = []

    if len(sys.argv) > 1:
        filename = sys.argv[1]
    else:
        print("Missing filename argument!")
        exit(0)

    print("Reading file..")
    with open(filename) as filehandler:
        # decode json
        jsonObject = json.load(filehandler)
        print("Creating objects..")
        for weapon in jsonObject['Weapons']:
            # create new instance of the class Weapon
            weaponObj = Weapon(weapon['name'], weapon['damage'], weapon['critical_strike_percent'], weapon['chance'])
            weapons.append(weaponObj)
        for hero in jsonObject['Heroes']:
            # create new instance of the class Hero
            heroObj = Hero(hero['name'], hero['health'], hero['maxHealth'], hero['nickname'], hero['weapon'])
            heroes.append(heroObj)
        for orc in jsonObject['Orcs']:
            # create new instance of the class Orc
            orcObj = Orc(orc['name'], orc['health'], orc['maxHealth'], orc['berserk_factor'], orc['weapon'])
            orcs.append(orcObj)

    print("\nResults:")
    # loop and print the objects:
    print("\nWeapons:")
    for weapon in weapons:
        print(weapon)
    print("\nHeroes:")
    for hero in heroes:
        print(hero)
    print("\nOrcs:")
    for orc in orcs:
        print(orc)
