#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)
#define all(v) (v).begin(), (v).end()

ll det(p v, p u){
    return v.first * u.second - v.second * u.first;
}

void solve() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    p v = {x2 - x1, y2 - y1};

    ll q; cin >> q;
    while(q--){
        ll x, y; cin >> x >> y;
        p u = {x - x1, y - y1};

        if (det(v, u) == 0){
            cout << "C\n";
        } else if (det(v, u) > 0){
            cout << "I\n";
        } else cout << "D\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}