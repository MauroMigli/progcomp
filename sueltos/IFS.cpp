#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)
int MOD = 1e9 + 7;


vector<pair<int, int>> child;
vector<int> parent;
vector<int> ans_down;
vector<int> ans_up;

int dp_down(int node){
    // si tiene hijos
    if (child[node].first && child[node].second){
        ans_down[node] += (dp_down(child[node].first) + 2) % MOD;
        ans_down[node] += (dp_down(child[node].second) + 2) % MOD;
    } else ans_down[node] = 0; // si no, se queda en 0

    return ans_down[node];
}

int dp_up(int node, int p){
    if (ans_up[node] != -1) return ans_up[node];

    if (node == 1 && p == 0){
        ans_up[node] = (ans_down[node] + 1) % MOD;
    } else {
        ans_up[node] = (ans_down[node] + 1 + dp_up(p, parent[p]) % MOD) % MOD;
    }
    return ans_up[node];
}

void solve(){
    int n; cin >> n;
    child.assign(n + 1, {0, 0}); // 0 -> {1, 0}
    parent.assign(n + 1, 0); parent[1] = 0; // NO CONTAR 0
    
    ans_down.assign(n + 1, 0);
    ans_up.assign(n + 1, -1);


    repk(i, 1, n + 1){
        int u, v; cin >> u >> v;
        child[i].first = u;
        child[i].second = v;
        parent[u] = i; parent[v] = i;
    }

    dp_down(1);
    for(int i = 1; i <= n; i++){
        cout << dp_up(i, parent[i]) << " ";
    }

    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}