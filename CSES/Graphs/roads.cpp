#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

struct DSU {
    int max_nodes;
    vector<int> parent;
    vector<int> size;

    DSU(int n){
        max_nodes = n;
        parent.assign(n, 0);
        rep(i, n) parent[i] = i;
        size.assign(n, 1);
    }
    int Find(int u){
        if (parent[u] == u) return u;
        return parent[u] = Find(parent[u]);
    }

    void Union(int u, int v){
        u = Find(u);
        v = Find(v);
        if (u == v) return;
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    DSU dsu(n);

    rep(j, m){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        dsu.Union(a, b);
    }

    set<int> reps;
    rep(i, n) reps.insert(dsu.Find(i));

    cout << reps.size() - 1 << '\n';
    
    deque<int> aristas;
    for(const auto& rep : reps){
        if (aristas.size() < 2) {
            aristas.push_back(rep);
            if (aristas.size() == 2) 
                cout << aristas.front() + 1 << ' ' << aristas.back() + 1 << '\n';
        }
        else if (aristas.size() == 2) {
            aristas.pop_front();
            aristas.push_back(rep);
            cout << aristas.front() + 1 << ' ' << aristas.back() + 1 << '\n';
        }
    }
    return 0;
}