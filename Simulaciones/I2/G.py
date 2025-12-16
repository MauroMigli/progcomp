def main():
    
    N = 100000

    is_prime = [True for i in range(N + 1)]
    def cribe():
        i = 2
        while i * i <= N:
            j = 2 * i
            while (j <= N):
                is_prime[j] = False
                j += i
            i += 1

    n = int(input())
    cribe()

    if (n == 2):
        print(-1)
        return
    
    c = 0
    primos = [0 for i in range(n)]

    for i in range(2, N + 1):
        if (is_prime[i]):
            primos[c] = i
            c += 1
        if (c == n):
            break

    for i in range(n):
        pitatoria = 1
        for j in range(n):
            if i == j:
                continue

            pitatoria *= primos[j]
        print(pitatoria)
    return