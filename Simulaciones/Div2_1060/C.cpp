#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repf(i, k, n) for(int i = 0; i < n; i++)

const ll MOD = 1e9 + 7;

ll MAX = 2e5;
vector<vector<int>> divisors(MAX + 1);

void sieve(){
    for(int i = 2; i < sqrt(2e5); i++){
        for(int j = i; j <= 2e5; j += i){
            divisors[j].push_back(i);
            if (j / i != i) divisors[j].push_back(j / i);
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    
    map<int, int> divisores_comunes;
    int unos = 0;
    int impares = 0;
    int pares = 0;

    rep(i, n) {
        cin >> A[i];
        if (A[i] == 1) unos++;
        pares += (A[i] + 1) % 2;
        if (A[i] != 1 && A[i] % 2 == 1) impares++;

        for(int div : divisors[A[i]]){
            divisores_comunes[div]++;
        }
    }
    rep(i, n) cin >> B[i];
    
    for(auto [div, freq] : divisores_comunes){
        if (freq > 1) {
            cout << 0 << endl;
            return;
        }
    }


    if (unos == n) {
        cout << 2 << endl;
        return;
    }
    if (pares >= 2){
        cout << 0 << endl;
        return;
    }
    if (pares == 0){
        cout << 2 << endl;
        return;
    }
    cout << 1 << endl;
}

int main() {
    fastio;
    sieve();
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
