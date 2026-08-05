#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

vector<vector<int>> G;
vector<bool> visited;
pair<int, int> arista;

void dfs(int u, int p){
    visited[u] = true;

    for(int v : G[u]){
        if (v == p) continue;
        if (visited[v]) {
            arista = {u + 1, v + 1};
            continue;
        }
        dfs(v, u);
    }
}

void solve() {
    int n; cin >> n;
    G.assign(n, {});
    visited.assign(n, false);
    rep(i, n - 1){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b); G[b].push_back(a);
    }

    vector<int> reps;
    rep(i, n){
        if (visited[i]) continue;
        dfs(i, -1);
        reps.push_back(i + 1);
    }

    if ((int)reps.size() == 1){
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
        cout << arista.first << ' ' << arista.second << ' ' << reps[0] << ' ' << reps[1] << endl;
    }
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