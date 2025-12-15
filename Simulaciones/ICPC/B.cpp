#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)

void solve() {
    int N, K; cin >> N >> K;

    vector<int> dp(min(N, K) + 1);

    repk(i, 1, min(N, K) + 1){
        for(int j = 1; j <= K; j += i){
            dp[i]++;
        }
    }
}

int main() {
    fastio()
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}