#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n, m; cin >> n >> m;
    set<pair<int, int>> A; 
    rep(j, m) {
        int a; cin >> a;
        A.insert({a, j});
    }

    vector<int> ans;
    rep(i, n){
        auto [mini, l] = *A.begin();
        auto [maxi, r] = *prev(A.end());
        if (l == r && i != n - 1) break;
        
        if (i % 2 == 1){
            ans.push_back(l + 1);
            A.erase({mini, l});
            if (mini) A.insert({mini - 1, l});
        } else {
            ans.push_back(r + 1);
            A.erase({maxi, r});
            if (maxi) A.insert({maxi - 1, r});
        }
        cout << "number " << i << ": {" << mini << ", " << l << "} | {" << maxi << ", " << r << "}\n";
    }
    if ((int)ans.size() == n) {
        for(int x : ans) cout << x << ' ';
        cout << endl;
    } else cout << -1 << endl;
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