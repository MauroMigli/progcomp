#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

vector<p> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

char to_direction(p par){
    if (par.first == 1) return 'D';
    else if (par.first == -1) return 'U';
    else if (par.second == 1) return 'R';
    else return 'L';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    vector<vector<p>> parent(n, vector<p>(m, {0, 0}));
    vector<vector<int>> dist(n, vector<int>(m));

    p start, end;
    
    rep(i, n){
        cin >> grid[i];
        rep(j, m){
            // INVERTIDO: hacemos el recorrido por padres invertido ya :)
            if (grid[i][j] == 'B') start = {i, j};
            if (grid[i][j] == 'A') end = {i, j};
        }
    }

    queue<p> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    dist[start.first][start.second] = 0;

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        for (auto [dx, dy] : d){
            bool in_border = 0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < m;
            if (in_border){
                if (grid[x + dx][y + dy] != '#' && !visited[x + dx][y + dy]){
                    q.push({x + dx, y + dy});
                    visited[x + dx][y + dy] = 1;
                    parent[x + dx][y + dy] = {-dx, -dy};
                    dist[x + dx][y + dy] = dist[x][y] + 1;
                    
                    if (grid[x + dx][y + dy] == 'A') break;
                }
            }
        }
    }

    if (visited[end.first][end.second] == 1){
        cout << "YES" << '\n';
        cout << dist[end.first][end.second] << '\n';
        
        auto [curr_x, curr_y] = end;
        while(parent[curr_x][curr_y] != make_pair(0, 0)){
            auto [px, py] = parent[curr_x][curr_y];
            cout << to_direction(parent[curr_x][curr_y]);
            curr_x += px; 
            curr_y += py;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}