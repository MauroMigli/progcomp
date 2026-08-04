#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

// BELLMAN-FORD (MAXIMIZING)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll INF = 1e12;

    ll n, m; cin >> n >> m;
    vector<vector<p>> G(n);
    vector<ll> score(n, -INF);

    score[0] = 0;
    rep(_, m) {
        ll a, b, x; cin >> a >> b >> x; a--; b--;
        G[a].push_back({x, b});
    }

    rep(_, n - 1){
        rep(u, n) for(auto [x, v] : G[u]){
            score[v] = max(score[v], score[u] + x);
        }
    }

    set<ll> glitched;
    rep(u, n) for(auto [x, v] : G[u]){
        if (score[v] < score[u] + x){
            glitched.insert(u);
        }
    }

    // Si 0 es uno de esos nodos, 
    if (glitched.count(0)) {
        cout << -1 << endl;
        return 0;
    }

    // BFS para encontrar los que no se pueden
    queue<ll> q;
    queue<ll> q_multi;
    vector<bool> visited(n, false);
    vector<bool> visited_multi(n, false);

    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        ll u = q.front(); q.pop();

        for(auto [x, v] : G[u]){
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
            if (glitched.count(v)) {
                q_multi.push(v);
                visited_multi[v] = true;
                glitched.erase(v);
            }
        }
    }

    while(!q_multi.empty()){
        ll u = q_multi.front(); q_multi.pop();

        for(auto [x, v] : G[u]){
            if(visited_multi[v]) continue;
            
            // Se alcanza el final desde un ciclo penca!
            if (v == n - 1){
                cout << -1 << endl;
                return 0;
            }
            visited_multi[v] = true;
            q_multi.push(v);
        }
    }

    cout << score[n - 1] << endl;

    return 0;
}