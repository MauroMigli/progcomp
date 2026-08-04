#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)

void solve(){
    ll n; cin >> n;
    if (n == 1){
        cout << 1 << endl;
    } else if (n == 2){
        cout << -1 << endl;
    } else {
        cout << 2 << ' ' << 4 << ' ';
        ll sum = 6;
        rep(i, n - 2){
            cout << sum << ' ';
            sum += sum;
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}