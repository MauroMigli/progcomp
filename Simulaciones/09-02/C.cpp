#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)
#define all(v) (v).begin(), (v).end()

ll n, x;

ll backtracking(ll i, ll curr_num, vector<vector<ll>>& A){
    if (i == n){        
        if (curr_num == x) return 1;
        else return 0;
    }
    
    ll ans = 0;
    
    ll L_i = (ll)A[i].size();

    rep(j, L_i){
        if ((x / curr_num) % A[i][j] == 0){
            ans += backtracking(i + 1, curr_num * A[i][j], A);
        }
    }

    return ans;
}

void solve() {
    cin >> n >> x;

    vector<vector<ll>> A(n);
    rep(i, n){
        ll l; cin >> l;

        rep(j, l){
            int a; cin >> a;
            A[i].push_back(a);
        }
    }

    cout << backtracking(0, 1, A) << '\n';
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