#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

ll mod = 1e9 + 7;

vector<bool> is_prime(int N){
    vector<bool> is_prime(N + 1, true);

    for(int i = 2; i * i <= N; i++){
        for(int j = 2 * i; j <= N; j += i){
            is_prime[j] = false;
        }
    }
    return is_prime;
}

void solve() {
    ll n; cin >> n;

    vector<bool> prime = is_prime(n);

    ll ans = 1;

    repk(i, 2, n + 1){
        if(prime[i]){
            ll p = i;
            ll e = 0;

            while(p <= n){
                e += n / p;
                e %= mod;
                p *= i;
            }
            ans *= (e + 1);
            ans %= mod;
        }
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