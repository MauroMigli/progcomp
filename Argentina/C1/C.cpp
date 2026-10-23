#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    ll d, k; cin >> d >> k;

    ll bound = 4 * d / k;
    
    ll p = 0, q = 0;
    
    bool utkarsh = true;
    rep(i, bound){
        if (utkarsh){
            p += k;
            utkarsh = false;
        } else {
            q += k;
            utkarsh = true;
        }
        if (p * p + q * q > d * d) break;
    }

    if (!utkarsh) cout << "Utkarsh" << '\n';
    else cout << "Ashish" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}