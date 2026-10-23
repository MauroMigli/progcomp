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
    ll n; cin >> n;
    vector<pair<ll, ll>> pf = prime_factorization(n);
    
    ll ans = 1;
    for(auto [_, exp] : pf){
        ans *= 2 * exp + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}