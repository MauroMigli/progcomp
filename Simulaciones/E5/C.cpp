#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(){
    int H, W, D; cin >> H >> W >> D;

    vector<string> A(H);
    
    vector<vector<int>> dist(H, vector<int>(W, -1));

    queue<pair<int, int>> q;
    rep(i, H){
        cin >> A[i];
        rep(j, W) if (A[i][j] == 'H') {
            q.push({i, j});
            dist[i][j] = 0;
        }
    }

    int ans = 0;
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        ans++;

        for(auto [dx, dy] : d){
            bool in_border = (0 <= x + dx && x + dx < H && 0 <= y + dy && y + dy < W);
            if (!in_border) continue;

            bool wall = A[x + dx][y + dy] == '#';
            bool visited = dist[x + dx][y + dy] != -1;
            bool out_of_reach = dist[x][y] + 1 > D;
            if (wall || visited || out_of_reach) continue;

            dist[x + dx][y + dy] = dist[x][y] + 1;
            q.push({x + dx, y + dy});
        }
    }

    cout << ans << endl;

    return 0;
}