#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, int> pci;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pci>> G(n);
    rep(_, m){
        int u, v; cin >> u >> v; u--; v--;
        char c; cin >> c;
        G[u].push_back({c, v}); G[v].push_back({c, u});
    }

    vector<int> dist(n, -1); dist[n - 1] = 0;
    queue<int> q; q.push(n - 1);

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(auto [_, v] : G[u]){
            if (dist[v] != -1) continue;

            q.push(v);
            dist[v] = dist[u] + 1;
        }
    }

    vector<int> layer;
    candidatos.push({dist[0], {'z', 0}});
    vector<bool> visited(n, false); visited[0] = true;
    vector<int> parent(n, -1);
    string s = "";
    
    while(!candidatos.empty()){
        auto [depth_inv, par] = candidatos.top(); candidatos.pop();
        auto [_, u] = par;

        if (u == n - 1) break;

        char mini = 'z';
        for(auto [c, v] : G[u]){
            if (visited[v] || dist[v] + 1 != dist[u]) continue;
            
            mini = min(mini, c);
        }
        for(pci p : G[u]){
            if (mini == p.first && !visited[p.second] && dist[p.second] + 1 == dist[u]){
                s += p.first;
                visited[p.second] = true;
                parent[p.second] = u;
                candidatos.push({dist[p.second], p});
            }
        }
    }
    vector<int> path(dist[0] + 1, -1);
    int i = dist[0];
    for(int curr = n - 1; curr != 0; curr = parent[curr]){
        path[i] = curr;
        i--;
    }
    path[0] = 0;
    cout << dist[0] << '\n';
    for(int u : path) cout << u + 1 << ' ';
    cout << '\n';
    cout << s << endl;
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