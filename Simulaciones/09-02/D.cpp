#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> A(n);
    vector<ll> prefix(n + 1);
    map<ll, vector<ll>> idxs;
    
    prefix[0] = 0;

    rep(i, n) {
        cin >> A[i];
        prefix[i + 1] = prefix[i] + A[i];
        idxs[prefix[i + 1]].push_back(i + 1);
    }

    ll ans = 0;
    rep(i, n){
        ll known = k + prefix[i];

        ll size = (ll)idxs[known].size();
        auto it = idxs.find(known);

        if (it == idxs.end()) continue;
        auto& vec = it->second;
        auto pos = upper_bound(vec.begin(), vec.end(), i);

        ans += (vec.end() - pos);        
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