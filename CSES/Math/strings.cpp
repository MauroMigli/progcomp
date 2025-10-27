#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)
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

int main(){
    factorial_mod();

    string s; cin >> s;
    int n = s.size();
    map<char, ll> freq;
    rep(i, n) freq[s[i]]++;

    ll ans = 1;
    ll size = n;
    for(auto [c, f]: freq){
        if (f == size) continue;
        
        ans = (ans * factoriales[size]) % MOD;
        ans = (ans * modInverse(factoriales[size - f], MOD)) % MOD;
        ans = (ans * modInverse(factoriales[f], MOD)) % MOD;

        size -= f;
    }
    cout << ans << endl;

    return 0;
}