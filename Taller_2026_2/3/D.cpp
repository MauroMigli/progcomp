#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

ll ceil(ll a, ll b){
    return a >= 0 ? (a + b - 1) / b : a / b;
}

ll floor(ll a, ll b){
    return a >= 0 ? a / b : (a - b + 1) / b;
}

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

void solve() {
    int q; cin >> q;
    while (q--){
        ll L, A, B; cin >> L >> A >> B;
        ll x_g, y_g;
        ll g = extended_gcd(A, B, x_g, y_g);

        if (L % g != 0) cout << -1 << '\n';
        else {
            ll x_0 = x_g * (L / g), y_0 = y_g * (L / g);

            ll low = ceil(-x_0 * g, B);
            ll high = floor(y_0 * g, A);
            
            if (low > high){
                cout << -1 << '\n';
            } else if (B > A){
                cout << x_0 + y_0 + low * (B - A) / g << '\n';
            } else {
                cout << x_0 + y_0 + high * (B - A) / g << '\n';
            }
        }
    }
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