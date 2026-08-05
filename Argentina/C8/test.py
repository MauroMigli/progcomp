import random

with open("input.txt", "w") as file:
    t = 10
    for i in range(t):
        n = random.randint(3, 50)
        m = random.randint(1, 20)
        lista = random.sample(range(1, 51), n)
        file.write(f"{n} {m}\n")
        file.write(" ".join(map(str, lista)) + "\n")