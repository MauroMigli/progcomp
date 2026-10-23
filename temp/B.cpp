#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

vector<p> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve() {
    int H, W, N; cin >> H >> W >> N;

    vector<vector<bool>> is_black(H, vector<bool>(W, false));

    int i = 0;
    int j = 0;
    int move = 0;

    while(N--){
        is_black[i][j] = !is_black[i][j];
        i = (i + d[move].first + H) % H;
        j = (j + d[move].second + W) % W;
        if (is_black[i][j]) move = (move + 3) % 4;
        else move = (move + 1) % 4;
    }

    rep(i, H){
        rep(j, W){
            cout << (is_black[i][j] ? '#' : '.');
        }
        cout << '\n';
    }
}

int main() {


    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}