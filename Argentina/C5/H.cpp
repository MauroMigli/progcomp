#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

struct DSU {
    int n;
    vector<int> size;
    vector<int> dad;

    DSU(int node_amount){
        n = node_amount;
        size.assign(n, 1);
        dad.resize(n); // Que el padre de cada indice sea si mismo.
    }

    int find(int u){
        if (dad[u] = u) return u;
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

vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    pair<int, int> start;

    rep(i, n) {
        cin >> grid[i];
        rep(j, m) {
            if (grid[i][j] == 'S') start = {i, j};
        }
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