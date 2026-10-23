#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
ll MOD = 998244353;

ll bin_pow(ll a, ll b){
    ll ans = 1;

    while (b > 0){
        if (b & 1) ans = (ans * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

void solve() {
    ll n, k; cin >> n >> k;
    ll ans = 1;
    k %= MOD;

    ans = (ans * k) % MOD;
    ans = (ans * bin_pow(k - 1, n - 1)) % MOD;
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