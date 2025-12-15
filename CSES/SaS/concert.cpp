#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)

void solve() {
    int n, m; cin >> n >> m;
    vector<int> H(n), T(m);

    rep(i, n) cin >> H[i];
    rep(j, m) cin >> T[j];

    sort(H.begin(), H.end());
    
    rep(j, m){
        int l = 0, r = m - 1;
        int mid;

        while (l < r){
            mid = l + (r - l) / 2;
            if (H[mid] <= T[j])
                l = mid;
            else r = mid - 1;
        }
    }

}

int main() {
    fastio()
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}