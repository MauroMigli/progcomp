#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repf(i, k, n) for(int i = k; i < n; i++)

vector<deque<ll>> memo;
vector<pair<ll, ll>> ans;
vector<vector<int>> adj;
vector<ll> T;

pair<ll, ll> res = {-1, 1e18};

void dfs(int u, int p){
    ll max_size = 0;
    ll nodo_max = -1;

    for (int v : adj[u]){
        if (p == v) continue;

        dfs(v, u);
        if (max_size < memo[v].size()){
            max_size = memo[v].size();
            nodo_max = v;
        }
    }

    if (nodo_max == -1) { // leaf node
        memo[u] = {T[u]};
        ans[u].first = T[u];
        ans[u].second = 0;
    }
    else { // small to large
        memo[u] = move(memo[nodo_max]); // a pointer?
        memo[u].push_front(T[u]);

        if (T[u] < ans[nodo_max].first){
            ans[u].first = ans[nodo_max].first;
            ans[u].second = ans[nodo_max].second + 1;
        } else {
            ans[u].first = T[u];
            ans[u].second = 0;
        }
    }

    for(int v: adj[u]){
        if (p == v || v == nodo_max) continue;
        rep(i, memo[v].size()) {
            memo[u][i + 1] += memo[v][i];

            if (
                ans[u].first < memo[u][i + 1] || 
                (ans[u].first == memo[u][i + 1] && i + 1 < ans[u].second)
            ){
                ans[u].first = memo[u][i + 1];
                ans[u].second = i + 1;
            }
        }
    }

    if (
        (ans[u].first > res.first || 
        (ans[u].first == res.first && ans[u].second < res.second)) && 
        u != 0
    ){
        res = ans[u];
    }
}

int main(){
    int n; cin >> n;
    memo.resize(n);
    ans.resize(n, {0, 0});
    adj.resize(n);
    T.resize(n);

    rep(i, n - 1) cin >> T[i + 1];
    
    rep(i, n - 1){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    cout << res.first << " " << res.second + 1 << endl;
    return 0;
}