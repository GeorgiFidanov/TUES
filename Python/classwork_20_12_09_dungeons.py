class Hero:
    def __init__(self, name, health, nickname):
        self.name = name
        self.health = health
        self.nickname = nickname
        self.current_health = health

    @staticmethod
    def add_life(n):
        p1.health = p1.health + n
        return p1.health

    def is_alive(self):
        if self.current_health > 0:
            return True
        else:
            return False


if __name__ == '__main__':
    p1 = Hero("Pegasus", 100, "Perry")
    print(p1.name)
    print(p1.health)
    print(p1.nickname)
    p1.add_life(20)
