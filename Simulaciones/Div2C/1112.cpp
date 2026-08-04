#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

void solve(){
    int n; cin >> n;
    vector<p> left(n);
    vector<p> right(n);
    rep(i, n){
        int l, r, u, v; cin >> l >> r >> u >> v;
        left[i] = {l, r};
        right[i] = {u, v};
    }

    int ans = 0;
    repk(m, 1, n + 1){
        int j = 1;
        rep(i, n){
            bool left_valid = left[i].first > j || left[i].second < j;
            bool right_valid = right[i].first > m - j + 1 || right[i].second < m - j + 1;
            if (left_valid && right_valid) j++;
            
            if (j == m + 1) {
                ans = m;
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}