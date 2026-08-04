#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)

vector<vector<ll>> dist;
vector<vector<ll>> G;

// FLOYD-WARSHALL

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll INF = 1e12;

    ll n, m, q; cin >> n >> m >> q;
    dist.assign(n, vector<ll>(n, INF));

    rep(j, m) {
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    rep(i, n) dist[i][i] = 0;

    // Logica de este for: fijamos primero un nodo puente.
    rep(k, n){
        rep(i, n){
            rep(j, n){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    

    while(q--){
        int a, b; cin >> a >> b; a--; b--;
        ll out = dist[a][b] >= 1e12 ? -1 : dist[a][b];
        cout << out << '\n';
    }
    return 0;
}