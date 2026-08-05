#include<bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> size;
    vector<int> dad;

    DSU(int node_amount){
        n = node_amount;
        size.assign(n, 1);
        dad.resize(n); // Que el padre de cada indice sea si mismo.
    }

    int find(int u){
        if (dad[u] = u) return u;
        return dad[u] = find(dad[u]);
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);

        if (size[u] < size[v]) swap(u, v);

        dad[v] = u; // la raiz chica se concatena a la raiz grande
        size[u] += size[v];
    }
};