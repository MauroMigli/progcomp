#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<bool> is_prime(1e5, true);

void cribe(){
    for(ll i = 2; i * i <= 1e5; i++){
        for(ll j = 2 * i; j <= 1e5; j += i){
            is_prime[j] = false;
        }
    }
}

int main(){
    ll n; cin >> n;
    cribe();

    ll c = 0;

    vector<ll> primos(n);
    
    for(ll i = 2; i <= 1e5; i++){
        if (is_prime[i]){
            primos[c] = i;
            c++;
        }
        if (c == n) break;
    }

    for(ll i = 0; i < n; i++){
        ll pitatoria = 1;
        for(ll j = 0; j < n; j++){
            if (i == j) continue;
            pitatoria *= primos[j];
        }
        cout << pitatoria << endl;
    }


    return 0;
}