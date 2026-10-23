#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
int M = 1e9 + 7;
 
vector<vector<int>> memo;
 
// 0 -> two closed separate
// 0.5 (no state) -> two closed same
// 1 -> one closed one open
// 2 -> two open separate
// 3 -> two open same
 
int dp(int i, int prev_pattern){
    if (memo[i][prev_pattern] != -1) return memo[i][prev_pattern];
    if (i == 0) return memo[i][prev_pattern] = !prev_pattern;
    
    int count = 0;
    if (prev_pattern == 0){ // two closed
        count += (2 * dp(i - 1, 0)) % M;
        count %= M;
        count += (2 * dp(i - 1, 1)) % M;
        count %= M;
        count += dp(i - 1, 2);
        count %= M;
        count += dp(i - 1, 3);
        count %= M;
    } else if (prev_pattern == 1){ // one closed one open
        count += dp(i - 1, 0);
        count %= M;
        count += (2 * dp(i - 1, 1)) % M;
        count %= M;
        count += dp(i - 1, 2);
        count %= M;
    } else if (prev_pattern == 2){ // two open separate
        count += dp(i - 1, 0);
        count %= M;
        count += (2 * dp(i - 1, 1)) % M;
        count %= M;
        count += dp(i - 1, 2);
        count %= M;
    } else { // two open same
        count += dp(i - 1, 0);
        count %= M;
        count += dp(i - 1, 3);
        count %= M;
    }
 
    return memo[i][prev_pattern] = count;
}
 
void solve(){
    int n; cin >> n;
 
    cout << dp(n, 0) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    memo.assign(1e6 + 1, vector<int>(4, -1));

    int t; cin >> t;
    while(t--) solve();
 
    return 0;
}