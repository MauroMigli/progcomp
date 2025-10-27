#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)
ll MOD = 1e9 + 7;

ll modpow(ll a, ll e, ll mod) {
    ll r = 1;
    a %= mod;
    while (e > 0) {
        if (e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}

ll modInverse(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}

ll modGeometricSum(ll r, ll n){
    return (
        ((modpow(r, n + 1, MOD) - 1) % MOD) * 
        modInverse(r - 1, MOD)
    );
}

int main(){
    ll n; cin >> n;
    vector<pair<ll, ll>> primes(n);
    
    ll cantidad = 1;
    ll suma = 1;
    ll producto = 1;

    bool cantidad_impar = true;
    rep(i, n){
        cin >> primes[i].first;
        cin >> primes[i].second; 

        ll p = primes[i].first;
        ll k = primes[i].second;

        cantidad = (cantidad * ((1 + k) % MOD)) % MOD;
        if ((1 + k) % 2 == 0) cantidad_impar = false;

        suma = (suma * ((modGeometricSum(p, k)) % MOD)) % MOD;
    }
    rep(i, n){
        ll p = primes[i].first;
        ll k = primes[i].second;
        
        if (cantidad_impar) producto = (producto * ((modpow(p, k / 2, MOD)))) % MOD;
        else producto = (producto * ((modpow(p, k, MOD)))) % MOD;
    }

    rep(i, n){
        if (!cantidad_impar && (primes[i].second + 1) % 2 == 0){
            producto = (modpow(producto, (primes[i].second + 1) / 2, MOD)) % MOD;
            cantidad_impar = true;
        }
        else producto = modpow(producto, (primes[i].second + 1), MOD) % MOD;
    }

    cout << cantidad % MOD << " ";
    cout << suma % MOD << " "; 
    cout << producto % MOD << endl;
    
    
    return 0;
}