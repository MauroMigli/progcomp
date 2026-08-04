#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

bool is_border(p par, int n, int m){
    auto [f, s] = par;
    return f == 0 || s == 0 || f == n - 1 || s == m - 1;
}

bool in_border(p par, int n, int m){
    auto [f, s] = par;
    return 0 <= f && f < n && 0 <= s && s < m;
}

char to_direction(p par){
    if (par.first == 1) return 'D';
    else if (par.first == -1) return 'U';
    else if (par.second == 1) return 'R';
    else return 'L';
}

vector<p> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    p start;
    queue<p> monsters;
    queue<p> q;
    vector<vector<int>> dist_monsters(n, vector<int>(m, INT_MAX));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<p>> parent(n, vector<p>(m, {0, 0}));

    rep(i, n) {
        cin >> grid[i];
        rep(j, m){
            if (grid[i][j] == 'A') {
                start = {i, j};
                q.push(start);
                dist[i][j] = 0;
            }
            if (grid[i][j] == 'M') {
                monsters.push({i, j});
                dist_monsters[i][j] = 0;
            }
        }   
    }
    if (is_border(start, n, m)) {
        cout << "YES\n";
        cout << 0 << '\n';
        return 0;
    }

    while(!monsters.empty()){
        auto [x, y] = monsters.front(); monsters.pop();

        for (auto [dx, dy] : d){
            if (!in_border({x + dx, y + dy}, n, m)) continue;
            if (grid[x + dx][y + dy] == '#') continue;
            if (dist_monsters[x + dx][y + dy] != INT_MAX) continue;

            dist_monsters[x + dx][y + dy] = dist_monsters[x][y] + 1;
            monsters.push({x + dx, y + dy});
        }
    }

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        for(auto [dx, dy] : d){
            if (!in_border({x + dx, y + dy}, n, m)) continue;
            if (grid[x + dx][y + dy] == '#') continue;
            if (dist[x + dx][y + dy] != INT_MAX) continue;

            dist[x + dx][y + dy] = dist[x][y] + 1;
            parent[x + dx][y + dy] = {-dx, -dy};
            q.push({x + dx, y + dy});
        }
    }

    p fin = {-1, -1};
    bool found = false;
    rep(i, n){
        if (found) break;
        if (grid[i][0] == '.'){
            if (dist[i][0] < dist_monsters[i][0]){
                fin = {i, 0};
                found = true;
            }
        }
        if (grid[i][m - 1] == '.'){
            if (dist[i][m - 1] < dist_monsters[i][m - 1]){
                fin = {i, m - 1};
                found = true;
            }
        }
    }
    rep(j, m){
        if (found) break;
        if (grid[0][j] == '.'){
            if (dist[0][j] < dist_monsters[0][j]){
                fin = {0, j};
                found = true;
            }
        }
        if (grid[n - 1][j] == '.'){
            if (dist[n - 1][j] < dist_monsters[n - 1][j]){
                fin = {n - 1, j};
                found = true;
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
        return 0;
    }

    stack<char> answer;
    p current_cord = fin;
    while(current_cord != start){
        auto [x, y] = current_cord;
        auto [dx, dy] = parent[x][y];
        answer.push(to_direction({-dx, -dy}));
        current_cord = {x + dx, y + dy};
    }

    cout << "YES\n";
    cout << answer.size() << endl;
    while(!answer.empty()){
        cout << answer.top(); answer.pop();
    }
    cout << endl;

    return 0;
}