#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repf(i, k, n) for (ll i = k; i < (n); i++)

void solve(){
    ll a, n; cin >> a >> n;
    ll d1, d2; cin >> d1 >> d2;

    string s = to_string(a);

    int candidato_1 = 0;
    int pot_10 = 1;
    rep(i, s.size() - 1){
        candidato_1 += pot_10 * max(d1, d2);
        pot_10 *= 10;
    }

    int candidato_2 = 0;
    pot_10 = 1;
    rep(i, s.size()){
        int digit;
        int dif_1 = abs(d1 - (s[s.size() - 1 - i] - '0'));
        int dif_2 = abs(d2 - (s[s.size() - 1 - i] - '0'));
        if (dif_1 < dif_2) digit = d1;
        else digit = d2;

        candidato_2 += pot_10 * digit;
        pot_10 *= 10;
    }

    cout << min(abs(candidato_1 - a), abs(candidato_2 - a)) << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();

    return 0;
}