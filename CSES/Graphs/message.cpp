#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);

    rep(j, m){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> q;
    q.push(n - 1);
    dist[n - 1] = 0;

    bool found = false;
    while(!q.empty()){
        int u = q.front(); q.pop();
        
        for(int v : G[u]){
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            parent[v] = u;
            q.push(v);
            
            if (v == 0) {
                found = true;
                break;
            }
        }
    }
    if (dist[0] == -1) cout << "IMPOSSIBLE" << endl;
    else {
        cout << dist[0] + 1 << '\n';
        int curr = 0;
        cout << curr + 1 << ' ';

        while(parent[curr] != -1){
            cout << parent[curr] + 1 << ' ';
            curr = parent[curr];
        }
        cout << endl;
    }

    return 0;
}