#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

vector<p> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    rep(i, n) cin >> grid[i];
    vector<vector<bool>> visited(n, vector<bool>(m, 0));

    int rooms = 0;
    rep(i, n) rep(j, m) {
        if ((visited[i][j] && grid[i][j] == '.')|| grid[i][j] == '#') continue;
        
        rooms++;
        queue<p> q;
        q.push({i, j});
        visited[i][j] = 1;

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();

            for (auto [dx, dy] : d){
                bool in_border = 0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < m;
                if (in_border){
                    if (grid[x + dx][y + dy] == '.' && !visited[x + dx][y + dy]){
                        q.push({x + dx, y + dy});
                        visited[x + dx][y + dy] = 1;
                    }
                }
            }
        }
    }
    
    cout << rooms << endl;

    return 0;
}