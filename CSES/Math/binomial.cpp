#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
ll MOD = 1e9 + 7;

vector<ll> factoriales(1e6 + 1);

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

void factorial_mod(){
    factoriales[0] = 1;
    for(ll i = 1; i <= 1e6; i++){
        factoriales[i] = (i * (factoriales[i - 1] % MOD)) % MOD;
    }
}

void solve(){
    ll a, b; cin >> a >> b;
    ll ans = factoriales[a] % MOD;
    ans = (ans * modInverse(factoriales[b], MOD)) % MOD;
    ans = (ans * modInverse(factoriales[a - b], MOD)) % MOD;
    cout << ans << '\n';
}

int main(){
    factorial_mod();

    ll t; cin >> t;
    while(t--) solve();
    
    return 0;
}