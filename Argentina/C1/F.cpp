#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    ll n, g, b; cin >> n >> g >> b;
    ll half = (n + 1) / 2;
    ll l = (half + g - 1) / g;
    ll ans = (g + b) * l;
    ans -= b;
    ans -= (l * g - half);

    if (n - half > (l - 1) * b) {
        ans += (n - half - (l - 1) * b);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}