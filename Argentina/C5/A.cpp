#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

vector<vector<int>> G;

void solve() {
    int n, m; cin >> n >> m;
    G.assign(n, {});
    vector<pair<int, int>> degree(n, {0, 0});
    rep(_, m) {
        int x, y; cin >> x >> y; x--; y--;
        G[x].push_back(y); G[y].push_back(x);
        degree[x].first++; degree[y].first++;
        degree[x].second = x; degree[y].second = y;
    }

    sort(degree.begin(), degree.end(), greater<pair<int, int>>());
    // Ahora queremos iterar por V * E y calcular. Ahora, esto en el orden.
    vector<int> reacted(n, false);
    int ans = 1;
    rep(i, n){
        auto [deg, u] = degree[i];
        for(int v : G[u]){
            if (reacted[v]) ans *= 2; break;
        }
        reacted[u] = true;
    }
    cout << ans << endl;
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