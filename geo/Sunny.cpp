#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

long double norm(long double dx, long double dy) {
    return sqrtl((long double)dx * dx + (long double)dy * dy);
}

void solve() {
    int n; cin >> n;
    
    vector<p> X(n); 
    rep(i, n){
        cin >> X[i].first >> X[i].second;
    }
    sort(X.begin(), X.end());
    
    vector<ll> suffix_max(n, 0);
    suffix_max[n - 1] = X[n - 1].second;
    for(int i = n - 2; i >= 0; i--){
        suffix_max[i] = max(X[i].second, suffix_max[i + 1]);
    }

    long double red = 0;
    for(int i = n - 2; i >= 0; i--){
        ll dx = X[i + 1].first - X[i].first;
        ll dy = X[i + 1].second - X[i].second;
        ll next_max = suffix_max[i + 1];

        if (dy >= 0) continue;
        else if (next_max <= X[i + 1].second) red += norm(dx, dy);
        else if (next_max >= X[i].second) continue;
        else {
            red += norm((next_max - X[i].second) * (static_cast<long double>(dx) / dy), next_max - X[i].second);
        }
    }
    cout << fixed << setprecision(2) << red << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}