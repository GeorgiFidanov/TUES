class Bill:
    def __init__(self):
        self.amount = None

    def init(self, amount):
        if type(amount) != int:
            raise TypeError("Expected Int!")

        self.amount = amount

    def str(self):
        return f"A {self.amount}$ bill"

    def int(self):
        return self.amount

    def hash(self):
        return self


class BillBatch:
    def __init__(self):
        self.bills = None

    def init(self, bills):
        self.bills = bills

    def total(self):
        ans = 0
        for bill in self.bills:
            ans += bill
        return ans


class CashDesk:
    def __init__(self):
        self.bills = None

    def init(self):
        self.bills = {}

    def total(self):
        ans = 0
        for key in self.bills:
            ans += self.bills[key] * int(key)
        return ans

    def take_money(self, money):
        if type(money) == Bill:
            if money not in self.bills:
                self.bills[money] = 0
            self.bills[money] += 1
        if type(money) == BillBatch:
            for bill in money:
                self.take_money(bill)

    def inspect(self):
        print(f"We have a total of {self.total()} in the desk")
        print("We have the following count of bills, sorted in ascending order:")
        for key in self.bills:
            print(f"{key} - {self.bills[key]}")
