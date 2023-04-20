import random


class Hero:
    def __init__(self, name, health, nickname):
        self.name = name
        self.health = health
        self.nickname = nickname
        self.current_health = health

    @staticmethod
    def add_life(bonus):
        p1.health = p1.health + bonus
        return p1.health

    def is_alive(self):
        if self.current_health > 0:
            return True
        else:
            return False


class Orc:
    def __init__(self, name, health, berserk_factor):
        self.name_orc = name
        self.health_orc = health
        self.berserk_factor_orc = berserk_factor
        self.current_health_orc = self.health_orc

        if berserk_factor > 2:
            print("Problem!")

        self.current_health_orc = self.health_orc

    def is_alive(self):
        if self.current_health_orc > 0:
            return True
        else:
            return False

    def get_health(self):
        return self.current_health_orc


class Weapon:
    def __init__(self, name, damage, critical_strike_percent):
        self.name_weapon = name
        self. damage_weapon = damage
        self.critical_strike_percent = critical_strike_percent

    def critical_hit(self):
        random_chance = random.uniform(0, 1)
        if random_chance <= self.critical_strike_percent:
            return True
        else:
            return False


if __name__ == '__main__':
    p1 = Hero("Pegasus", 100, "Perry")
    orc1 = Orc("Torbjorn", 75, 50)
    print(p1.name)
    print(p1.health)
    print(p1.nickname)
    print(orc1.name_orc)
    print(orc1.health_orc)
    print(orc1.berserk_factor_orc)

    p1.add_life(40)
