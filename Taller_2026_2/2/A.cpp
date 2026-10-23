#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    
    if (n == 1) {
        cout << "NO" << '\n';
        return;
    }

    for(int i = 2; i * i <= n; i++){
        if (n % i == 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "SI" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}