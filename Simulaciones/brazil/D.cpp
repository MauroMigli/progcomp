#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n, x, y; cin >> n >> x >> y;
    int size = (1 << n);
    vector<pair<int, int>> esquinas = {
        {0, 0}, {size, 0}, {0, size}, {size, size}
    };

    vector<vector<int>> grid_dist(size + 1, vector<int>(size + 1, -1));
    queue<pair<int, int>> q;
    
    pair<int, int> node = {(size) / 2, (size) / 2};
    q.push(node);
    grid_dist[node.first][node.second] = 0;

    while(!q.empty()){
        node = q.front();
        q.pop();

        for(auto [esq_x, esq_y] : esquinas){
            pair<int, int> neigh = {
                (node.first + esq_x) / 2, (node.second + esq_y) / 2
            };
            if (grid_dist[neigh.first][neigh.second] == -1){
                grid_dist[neigh.first][neigh.second] = grid_dist[node.first][node.second] + 1;
                q.push(neigh);
                
                if (neigh.first == x && neigh.second == y) break;
            }
        }
    }
    
    cout << grid_dist[x][y] << endl;
    return 0;
}