#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

// BICOLOREO

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> color(n, -1);
    
    rep(j, m){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, n){
        if (color[i] != -1) continue;
        
        stack<int> st;
        st.push(i);
        color[i] = 1;

        while(!st.empty()){
            int u = st.top(); st.pop();

            for(int v : G[u]){
                if (color[v] == color[u]) {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                } else if (color[v] != -1) continue;
                
                color[v] = !color[u];
                st.push(v);
            }
        }
    }
    rep(i, n){
        cout << color[i] + 1 << " ";
    }
    cout << endl;

    
    return 0;
}