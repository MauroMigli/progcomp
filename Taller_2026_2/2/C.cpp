#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

vector<pair<ll, ll>> prime_factorization(ll n){
    vector<pair<ll, ll>> pf;

    for(ll i = 2; i * i <= n; i++){
        ll exp = 0;

        while(n % i == 0){
            exp++;
            n /= i;
        }

        if (exp){
            pf.push_back({i, exp});
        }
    }

    if (n > 1){
        pf.push_back({n, 1});
    }
    return pf;
}

void solve() {
    ll x; cin >> x;

    ll y = 1;
    vector<pair<ll, ll>> pf = prime_factorization(x);
    for(auto [base, exp] : pf){
        if (exp % 2 == 1){
            y *= base;
        }
    }

    cout << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}