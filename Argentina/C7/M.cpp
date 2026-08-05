#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    ll n; cin >> n;
    vector<ll> prefix(n + 1, 0);
    vector<ll> A(n); rep(i, n) cin >> A[i];
    sort(A.begin(), A.end());

    rep(i, n) prefix[i + 1] = prefix[i] + A[i];

    int ans = 0;
    rep(i, n){
        auto it = upper_bound(A.begin(), A.end(), A[i] + 1);
        int idx = it - A.begin();
        if (idx == i) continue;

        ans += (prefix[n] - prefix[idx] - A[i] * (n - idx));
    }
    cout << ans << endl;
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