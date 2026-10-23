#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<int> idxs;
    
    idxs.insert(0);
    bool one = s[0] != '1';
    repk(i, 1, n){
        if (one && s[i] == '1'){
            idxs.insert(i);
            one = false;
        } else if (!one && s[i] == '0'){
            idxs.insert(i);
            one = true;
        }
    }

    if ((int)idxs.size() == n){
        cout << 0 << '\n';
        return;
    }

    int ones = 0;
    int zeros = 0;
    rep(i, n){
        if (!idxs.count(i) && s[i] == '1') ones++;
        else if (!idxs.count(i) && s[i] == '0') zeros++;
    }

    if (abs(ones - zeros) <= 1) cout << ones + zeros << '\n';
    else cout << -1 << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}