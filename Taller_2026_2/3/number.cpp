#include <bits/stdc++.h>
using namespace std;

// 1. Algoritmo de Euclides (O(log min(a,b)))
// Calcula el máximo común divisor (GCD)
long long gcd_euclides(long long a, long long b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Calcula el mínimo común múltiplo (LCM)
long long lcm_euclides(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return abs(a / gcd_euclides(a, b) * b);
}

// 2. Euclides Extendido y Bézout
// Retorna g y actualiza x, y tal que a*x + b*y = g
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// 3. Inverso Modular (Euclides Extendido)
// Retorna x tal que (a*x) % m == 1. Existe si gcd(a, m) == 1
long long mod_inverse(long long a, long long m) {
    long long x, y;
    long long g = extended_gcd(a, m, x, y);
    if (g != 1) return -1;
    return ((x % m) + m) % m; // Normalizamos para evitar residuos negativos en C++
}

// 4. Inverso Modular (Fermat) - O(log p)
// Exponenciación binaria rápida
long long binexp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Retorna a^(p-2) mod p. Solo válido estrictamente si p es primo
long long mod_inverse_fermat(long long a, long long p) {
    return binexp(a, p - 2, p);
}

int main(){
    // Fast I/O: Optimización de entrada/salida
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int consultas;
    cin >> consultas;
    
    // Procesar casos de prueba
    while (consultas--) {
        long long a, b, m;
        cin >> a >> b >> m;

        cout << "--- Resultados para a=" << a << ", b=" << b << ", m=" << m << " ---\n";
        
        cout << "GCD: " << gcd_euclides(a, b) << "\n";
        cout << "LCM: " << lcm_euclides(a, b) << "\n";

        long long x, y;
        long long g = extended_gcd(a, b, x, y);
        cout << "Bezout: " << a << "*(" << x << ") + " << b << "*(" << y << ") = " << g << "\n";

        long long inv_ext = mod_inverse(a, m);
        if (inv_ext != -1) {
            cout << "Inverso mod " << m << " (Euclides Ext): " << inv_ext << "\n";
        } else {
            cout << "Inverso mod " << m << " (Euclides Ext): NO EXISTE\n";
        }

        long long inv_fermat = mod_inverse_fermat(a, m);
        cout << "Inverso mod " << m << " (Fermat): " << inv_fermat << "\n\n";
    }
    return 0;
}