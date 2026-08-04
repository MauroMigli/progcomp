#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)

vector<ll> l; 
vector<ll> memo;
vector<ll> A;

ll dp(ll i){
    if (i == -1) return 0;
    if (memo[i] != -1) return memo[i];
    return memo[i] = max(
        dp(l[A[i]] - 1) + (i - l[A[i]] + 1) * (i - l[A[i]] + 1),
        dp(i - 1) + 1
    );
}

void solve(){
    ll n; cin >> n;
    A.assign(2 * n, -1);
    l.assign(n + 1, -1);
    memo.assign(2 * n, -1);
    
    rep(i, 2 * n) {
        cin >> A[i];
        if (l[A[i]] == -1) l[A[i]] = i;
    }
    cout << dp(2 * n - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}