#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

vector<int> visited;
vector<int> parent;
vector<int> cycle;
vector<vector<int>> G;
int start = -1;
int fin = -1;

// ENCONTRAR CICLOS

bool dfs(int u){
    visited[u] = 1;
    for(int v : G[u]){
        if (v == parent[u]) continue;
        if (visited[v] == 1){
            // Found
            parent[v] = u;
            start = u; 
            fin = v;
            return true;
        } else if (!visited[v]){
            parent[v] = u;
            if (dfs(v)) return true;
        }
    }
    visited[u] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    G.assign(n, {});
    visited.assign(n, 0);
    parent.assign(n, -1);

    rep(_, m){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, n){
        if (visited[i]) continue;
        // DFS
        if (dfs(i)) break;
    }

    if (start == -1) cout << "IMPOSSIBLE" << endl;
    else {
        cycle.push_back(start);
        for(int u = parent[start]; u != start; u = parent[u]) 
            cycle.push_back(u);
        cycle.push_back(start);
        
        cout << cycle.size() << '\n';
        for(int x : cycle) cout << x + 1 << ' ';
        cout << endl;
    }
    return 0;
}