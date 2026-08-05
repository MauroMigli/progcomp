#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

struct DSU {
    int n, m;
    map<pair<int, int>, int> size;
    map<pair<int, int>, pair<int, int>> dad;
    DSU(int n, int m){
        n = n;
        m = m
        rep(i, n) rep(j, m)
    }

    int find(int u){
        if (dad[u] == u) return u;
        return dad[u] = find(dad[u]);
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if (size[u] < size[v]) swap(u, v);
        dad[v] = u; // la raiz chica se concatena a la raiz grande
        size[u] += size[v];
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    vector<pair<int, int>> walls;

    rep(i, n) rep(j, m){
        if (grid[i][j] == '*') walls.push_back({i, j});
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