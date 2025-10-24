#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
ll MOD = 1e9 + 7;

ll gauss(ll n){
    ll a, b;
    if (n % 2 == 0) {
        a = n / 2;
        b = n + 1;            
    } else {
        a = n;
        b = (n + 1) / 2;
    }
    return ((a % MOD) * (b % MOD)) % MOD;
}

int main(){
    ll N; cin >> N;

    ll ans = N % MOD;
    ll pivot = 2;
    ll curr_freq = N / 2;
    
    while(pivot <= N){
        if (pivot == N){
            ans = (ans + N % MOD) % MOD;
            cout << "hasta aca llegamo";
            break;
        }
        
        ll l = (N / curr_freq);

        ll sum_pivot = gauss(pivot - 1);
        ll sum_l = gauss(l);

        ans = (ans + ((sum_l - sum_pivot + MOD) % MOD) * (curr_freq % MOD)) % MOD;

        pivot = l + 1;
        curr_freq = N / pivot;
    }
    cout << ans << endl;
    return 0;
}