#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> A(n);
    vector<vector<int>> adj(n);
    vector<int> color(n, -1); // no visitado si -1
    vector<int> indegree(n);

    rep(i, n){
        int u; cin >> u; u--; A[i] = u;
        adj[u].push_back(i);
        adj[i].push_back(u);
        indegree[u]++;
    }

    queue<int> q;
    rep(i, n){
        if (!indegree[i]) q.push(i);
    }

    // 1. Recorrer arboles invertidos
    while(!q.empty()){
        int u = q.front(); q.pop();
        bool colorear = true;
        for(int v : adj[u]){ 
            if (color[v] == 1){
                colorear = false;
                break;
            }
        }
        if (colorear) color[u] = 1;
        else color[u] = 0;

        indegree[A[u]]--;
        if (indegree[A[u]] == 0) q.push(A[u]);
    }

    // 2. Recorrer ciclos
    int ans = 0;
    rep(i, n){
        if (color[i] == 1) {
            ans++;
            continue;
        }

        int u = i;
        int start_size = 0;
        int current_size = 0;
        bool at_start = true;

        while(color[u] == -1){
            bool coloreable = true;
            for(int v : adj[u]) if (color[v] == 1){
                coloreable = false;
                break;
            }

            if (at_start){
                if (coloreable) start_size++;
                else at_start = false;
            } else {
                if (coloreable) current_size++;
                else {
                    ans += (current_size + 1) / 2;
                    current_size = 0;
                }
            }
            color[u] = 0;
            u = A[u];
        }
        if (at_start) ans += start_size / 2;
        else ans += (start_size + current_size + 1) / 2;
    }

    cout << ans << endl;

    return 0;
}