import json
import random
import string
import requests
import sys
import os
import time


def generate_special_json(service_name):
    names = ["Konstantin", "Andrey", "Alexander"]
    cities = ["Moscow", "Saint-Petersburg", "Kazan", "Sochi", "Novosibirsk"]
    
    
    data = {
        "index": service_name,
        "time": str(int(time.time() * 1000)),
        "data": dict()
    }

    data["data"]["name"] = random.choice(names)
    data["data"]["course"] = 3
    data["data"]["location"] = dict()
    data["data"]["location"]["country"] = "Russia"
    data["data"]["location"]["city"] = random.choice(cities)
    data["data"]["university"] = "MEPhI"

    return data


def generate_random_word():
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for i in range(random.randint(1, 10)))


def generate_json(service_name):
    types = [str(), int(), list()]
    data = {
        "index": "",
        "data": dict(),
        "time": 0

    }

    data["index"] = service_name
    data["time"] = str(int(time.time() * 1000))

    single_keys = []
    double_keys = []
    triple_keys = []

    for j in range(random.randint(1, 7)):
        single_keys.append(f"single_key_{j + 1}")

    for j in range(random.randint(1, 4)):
        double_keys.append(f"double_key_{j + 1}")

    for j in range(random.randint(1, 4)):
        triple_keys.append(f"triple_key_{j + 1}")

    for j in range(len(single_keys)):
        data["data"][single_keys[j]] = random.choice(types)

        if isinstance(data["data"][single_keys[j]], str):
            data["data"][single_keys[j]] = generate_random_word()
        elif isinstance(data["data"][single_keys[j]], int):
            data["data"][single_keys[j]] = random.randint(1, 1000000)
        else:
            for k in range(random.randint(1, 10)):
                if len(data["data"][single_keys[j]]) == 10:
                    break
                data["data"][single_keys[j]].append(random.randint(1, 1000000))

    for j in range(len(double_keys)):
        data["data"][double_keys[j]] = dict()

        double_values = set()
        for k in range(random.randint(1, 14)):
            double_values.add(random.choice(single_keys))

        for k in double_values:
            data["data"][double_keys[j]][k] = random.choice(types)

            if isinstance(data["data"][double_keys[j]][k], str):
                data["data"][double_keys[j]][k] = generate_random_word()
            elif isinstance(data["data"][double_keys[j]][k], int):
                data["data"][double_keys[j]][k] = random.randint(1, 1000000)
            else:
                for z in range(random.randint(1, 10)):
                    if len(data["data"][double_keys[j]][k]) == 10:
                        break
                    data["data"][double_keys[j]][k].append(random.randint(1, 1000000))

    for j in range(len(triple_keys)):
        data["data"][triple_keys[j]] = dict()

        triple_values = set()

        for k in range(random.randint(1, 14)):
            triple_values.add(random.choice(double_keys))

        for k in triple_values:
            data["data"][triple_keys[j]][k] = dict()

            double_values = set()

            for z in range(random.randint(1, 14)):
                double_values.add(random.choice(single_keys))

            for z in double_values:
                data["data"][triple_keys[j]][k][z] = random.choice(types)

                if isinstance(data["data"][triple_keys[j]][k][z], str):
                    data["data"][triple_keys[j]][k][z] = generate_random_word()
                elif isinstance(data["data"][triple_keys[j]][k][z], int):
                    data["data"][triple_keys[j]][k][z] = random.randint(1, 1000000)
                else:
                    for m in range(random.randint(1, 10)):
                        if len(data["data"][triple_keys[j]][k][z]) == 10:
                            break
                        data["data"][triple_keys[j]][k][z].append(random.randint(1, 1000000))

    return data

def send_json(service_name="default_service", transfer_type=False, path="json"):
    if transfer_type:
        print("Sending jsons to: http://192.168.1.3:8080/api\n")
    else:
        print("Generating jsons...\n")

    i = 1
    timing = int(time.time() * 1000)
    while True:
        if i % 20 == 0:
            data = generate_special_json(service_name)
        else:
            data = generate_json(service_name=service_name)
        if transfer_type:
            print("sending json №", i, data, sep=' ', end='\n')
            url = "http://192.168.1.3:8080/api"
            try:
                resp = requests.post(url, json=data, timeout=0.333)
            except:
                pass
        else:
            if not os.path.exists(path):
                os.makedirs(path)
            with open(f"{path}/json_file_{timing}.json", 'w') as json_file:
                json.dump(data, json_file)
        i += 1


if __name__ == "__main__":
    if len(sys.argv) == 1:
        send_json()
    elif len(sys.argv) == 2:
        send_json(service_name=sys.argv[1])
    elif len(sys.argv) == 3:
        send_json(service_name=sys.argv[1], transfer_type=(int(sys.argv[2]) > 0))
    elif len(sys.argv) == 4:
        send_json(service_name=sys.argv[1], transfer_type=(int(sys.argv[2]) > 0), path=sys.argv[3])
    else:
        raise Exception("too many arguments")

    print("Done")
