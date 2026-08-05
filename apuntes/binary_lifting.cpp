#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()


struct LCA {
    int n;
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;

    LCA(int n, vector<vector<int>> G, vector<int> p) {
        // Assign up matrix
        LOG = __lg(n) + 1;
        up.assign(n, vector<int>(LOG));
        depth.assign(n, 0);

        // Assign depth with DFS
        dfs(0, 0, 0, G);

        for(int j = 1; 1 << j < n; j++){
            rep(i, n){
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    void dfs(int u, int p, int d, vector<vector<int>>& G){
        up[u][0] = p;
        depth[u] = d;
        for(int v : G[u]){
            if (v == p) continue;
            dfs(v, u, d + 1, G);
        }
    }

    int get_lca(int u, int v){
        if (depth[u] > depth[v]) swap(u, v);
        
        int dif = depth[v] - depth[u];
        rep(j, LOG){
            if ((dif >> j) & 1){
                v = up[v][j];
            }
        }

        if (u == v) return v;
        
        for(int j = LOG - 1; j >= 0; j--){
            if (up[u][j] != up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    int get_dist(int u, int v){
        return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
    }

    int get_kth_ancestor(int u, int k){
        if (depth[u] < k) return -1;
        rep(j, LOG){
            if ((k >> j) & 1) u = up[u][j];
        }
        return u;
    }
};