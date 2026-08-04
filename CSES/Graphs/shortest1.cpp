#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)

// DIJKSTRA

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; cin >> n >> m;
    vector<vector<p>> G(n);
    vector<ll> dist(n, LLONG_MAX);
    rep(j, m) {
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        G[a].push_back({c, b});
    }

    priority_queue<p, vector<p>, greater<p>> pq;
    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for(auto [c, v] : G[u]){
            if (d + c >= dist[v]) continue;
            dist[v] = d + c;
            pq.push({d + c, v});
        }
    }

    rep(i, n) cout << dist[i] << ' ';
    cout << endl;

    return 0;
}