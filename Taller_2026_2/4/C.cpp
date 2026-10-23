#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()



int n, m;
string W;

vector<p> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int backtracking(int i, int j, int position, vector<string>& A, vector<vector<bool>> visited){
    if (W[position] != A[i][j]) return 0;
    if (position == (int)W.size() - 1) return 1;


    int ans = 0;
    for(auto [dx, dy] : d){
        bool in_border = 0 <= i + dx && i + dx < n && 0 <= j + dy && j + dy < m;
        
        if (in_border){
            if (!visited[i + dx][j + dy] && W[position + 1] == A[i + dx][j + dy]){
                visited[i + dx][j + dy] = true;
                ans += backtracking(i + dx, j + dy, position + 1, A, visited);
                visited[i + dx][j + dy] = false;
            }
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    vector<string> A(n);
    rep(i, n) cin >> A[i];

    cin >> W;
    int ans = 0;
    rep(i, n){
        rep(j, m){
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            visited[i][j] = true;
            ans += backtracking(i, j, 0, A, visited);
        }
    }
    cout << ans <<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}