#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

vector<vector<vector<int>>> memo;

double dp(int a, int b, int c){
    if (memo[a][b][c] != -1.0) return memo[a][b][c];
    if (a == 100 || b == 100 || c == 100){
        return 0.0;
    }

    return memo[a][b][c] = (
        dp(a + 1, b, c) * (static_cast<double>(a) / (a + b + c)) + 
        dp(a, b + 1, c) * (static_cast<double>(b) / (a + b + c)) + 
        dp(a, b, c + 1) * (static_cast<double>(c) / (a + b + c))
    );
}

void solve() {
    int a, b, c; cin >> a >> b >> c;

    memo.assign(100, vector<vector<double>>(100, vector<double>(-1.0)));
    cout << dp(a, b, c) << '\n';
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