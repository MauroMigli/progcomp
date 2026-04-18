#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll M = 1e9 + 7;


ll power(ll base, ll exp) {
    ll res = 1;
    base %= M;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % M;
        base = (base * base) % M;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, M - 2);
}

ll modDivide(ll a, ll b) {
    a %= M;
    ll inv = modInverse(b);
    return (a * inv) % M;
}


vector<pair<ll, ll>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<pair<ll, ll>> esq = {{1, 1},  {1, -1}, {-1, 1}, {-1, -1}};

int main() {
    ll n, m, d_0, d_1, d_2; cin >> n >> m >> d_0 >> d_1 >> d_2;

    vector<string> A(n);
    rep(i, n) cin >> A[i];

    ll E = 0;

    rep(i, n) rep(j, m){
        if (A[i][j] == 'V') E = (E + d_0) % M;
        else {
            ll y_0 = A[i][j] == '?';
            ll n_1 = 0;

            bool broke = false;
            for(auto [dx, dy] : adj){
                if (0 <= i + dx && i + dx < n && 0 <= j + dy && j + dy < m){
                    if (A[i + dx][j + dy] == 'V'){
                        E = (E + modDivide(y_0 * d_0,  2) + modDivide(d_1 * (2 - y_0), 2)) % M;
                        broke = true;
                        break;
                    }
                    n_1 += A[i + dx][j + dy] == '?';
                }
            }

            if (broke) continue;
            ll n_2 = 0;
            ll pot_2_n1 = (1 << n_1);
            broke = false;

            for(auto [dx, dy] : esq){
                if (0 <= i + dx && i + dx < n && 0 <= j + dy && j + dy < m){
                    if (A[i + dx][j + dy] == 'V'){

                        E = (E + modDivide(y_0 * d_0, 2) + modDivide(d_1 * (2 - y_0) * (pot_2_n1 - 1), pot_2_n1 * 2) + modDivide(d_2 * (2 - y_0), pot_2_n1 * 2)) % M;
                        broke = true;
                        break;
                    }
                    n_2 += A[i + dx][j + dy] == '?';

                }
            }
            if (broke) continue;
            ll pot_2_n2 = (1 << n_2);
            E = (E + modDivide(y_0 * d_0, 2) + modDivide(d_1 * (2 - y_0) * (pot_2_n1 - 1), pot_2_n1 * 2) + modDivide(d_2 * (2 - y_0) * (pot_2_n2 - 1), pot_2_n1 * pot_2_n2 * 2)) % M;
        }
    }

    cout << E << endl;

    return 0;
}
