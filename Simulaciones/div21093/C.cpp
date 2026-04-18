#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repk(i, k, n) for(ll i = k; i < n; i++)
typedef long long ll;


void solve(){
    ll p, q; cin >> p >> q;

    ll C = p + 2 * q;

    // escogemos cualquier combinacion de primos???
    for(ll i = 3; i * i <= 2 * C + 1; i++){
        if ((2 * C + 1) % i != 0) continue;  
        ll X = i;
        ll Y = (2 * C + 1) / X;
        ll n = (X - 1) / 2;
        ll m = (Y - 1) / 2;
        
        ll maximo_valido = n * m + min(n, m);
        if (q <= maximo_valido){
            cout << n << " " << m << '\n'; 
        }
    }
    cout << -1 << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
    
    return 0;
}