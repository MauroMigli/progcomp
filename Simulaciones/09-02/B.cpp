#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int l, r; cin >> l >> r; l--; r--;
    string s; cin >> s;
    // Hay una forma de revertirlo brutamente?

    rep(i, l){
        cout << s[i];
    }

    rep(i, r - l + 1){
        cout << s[r - i];
    }
    
    repk(i, r + 1, (int)s.size()){
        cout << s[i];
    }
    cout << '\n';
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