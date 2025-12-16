#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define node first
#define weight second

void solve(int i){
    int n, k, m; cin >> n >> k >> m;

    vector<vector<pair<int, int>>> adj(n);

    rep(i, m){
        int L; cin >> L;
        int prev = i;

        rep(j, L){
            int u; cin >> u; u--;
            adj[prev].push_back({u, 0});
            prev = u;
        }
    }

    queue<pair<int, int>> q; q.push({0, 0});

    int dist = 0;
    
    while(!q.empty()){
        auto [u, w] = q.front(); q.pop();
        

    }




    // si con el tiempo no se arregla, no lo hará.
    
    // ñ

    // eñe
}

int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    
    return 0;
}