#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)
#define all(v) (v).begin(), (v).end()

bool in_diag(ll a, ll b, ll c, ll d){
    return a + b == c + d || a - b == c - d;
}

bool near(ll a, ll b, ll c, ll d){
    return abs(a - c) + abs(b - d) <= 3;
}

bool same_color(ll a, ll b, ll c, ll d){
    return (a + b) % 2 == (c + d) % 2;
}

void solve() {
    ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    

    if (r1 == r2 && c1 == c2){
        cout << 0 << '\n';
    } else if (near(r1, c1, r2, c2)){
        cout << 1 << '\n';
    } else if (in_diag(r1, c1, r2, c2)){
        cout << 1 << '\n';
    } else if (same_color(r1, c1, r2, c2)){
        cout << 2 << '\n';
    } else {
        vector<pair<ll, ll>> d;
        rep(i, 4){
            rep(j, 4){
                if (i + j <= 3 && i + j != 0){
                    d.push_back({i, j}); d.push_back({-i, j});
                    d.push_back({i, -j}); d.push_back({-i, -j});
                }
            }
        }

        for(auto [dx, dy] : d){
            if (near(r1 + dx, c1 + dy, r2, c2)){
                cout << 2 << '\n';
                return;
            } else if (in_diag(r1 + dx, c1 + dy, r2, c2)){
                cout << 2 << '\n';
                return;
            }
        }
        cout << 3 << '\n';
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