import time
import random
import threading
from queue import Queue
import os
from bulb import Bulb

BULBS = 4
TECHNICIANS = 2


def create_directory(directory_path):
    if not os.path.exists(directory_path):
        os.makedirs(directory_path)


def bulb_functioning(bulb):
    while 1:
        state = random.randint(0, 100)
        if state < 40:
            bulb.break_bulb()
            manager_queue.put(bulb)
            manager_event.set()
            manager_event.clear()
            bulb.event.wait()
        else:
            brightness = random.randint(70, 90)
            colour = random.choice(["blue", "red", "white", "green"])
            bulb.update_indicators(brightness, colour)

        time.sleep(random.randint(3, 5))


def technician_fix_bulb(technician_id, bulb):
    bulb.fix_bulb(technician_id)
    bulb.event.set()
    bulb.event.clear()
    available_technicians.put(technician_id)


def manager():
    while True:
        manager_event.wait()
        while not manager_queue.empty():
            if not available_technicians.empty():
                threading.Thread(target=technician_fix_bulb, args=(available_technicians.get(),
                                                                   manager_queue.get()), daemon=True).start()


if __name__ == "__main__":
    create_directory("digital-twins")
    manager_thread = threading.Thread(target=manager, daemon=True)
    manager_queue = Queue()
    manager_event = threading.Event()

    manager_thread.start()

    available_technicians = Queue()
    for i in range(TECHNICIANS):
        available_technicians.put(i + 1)

    bulb_numbers = [i + 1 for i in range(BULBS)]
    bulb_thing_ids = ["bulb-" + str(num) for num in bulb_numbers]
    bulbs = [Bulb(bulb_thing_ids[i], bulb_numbers[i]) for i in range(BULBS)]

    bulb_threads = []
    for bulb in bulbs:
        ft = threading.Thread(target=bulb_functioning, args=(bulb,), daemon=True)
        bulb_threads.append(ft)

    for ft in bulb_threads:
        ft.start()
        time.sleep(1)

    for ft in bulb_threads:
        ft.join()
