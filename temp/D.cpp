#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)
#define all(v) (v).begin(), (v).end()

vector<p> player = {{0, 0}, {0, 0}};
ll n; 
vector<string> grid;
ll INF = 1e18;

vector<p> d = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void solve() {
    cin >> n;
    grid.assign(n, "");

    vector<vector<vector<int>>> visited;
    visited.assign(n, vector<vector<bool>>(n, vector<bool>(n * n + 1, false)));    
    

    ll found = 0;
    rep(i, n) {
        cin >> grid[i];
        rep(j, n){
            if (grid[i][j] == 'P'){
                player[found] = {i, j};
                found++; 
            }
        }
    }

    queue<pair<p, ll>> q; q.push({{player[0], player[1]}, 0});
    visited[][][0]

    while(!q.empty()){

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}