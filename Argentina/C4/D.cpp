#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    vector<int> L(n), R(n);
    vector<int> balance(n + 1, 0);

    int delta = 0;
    rep(i, n) {
        cin >> L[n - i - 1];
        L[n - i - 1] = L[n - i - 1] == 1 ? 1 : -1;
        delta += L[n - i - 1];
    }
    rep(i, n) {
        cin >> R[i];
        R[i] = R[i] == 1 ? 1 : -1;
        delta += R[i];
    }

    // Caso 1
    if (delta == 0) {
        cout << 0 << endl;
        return;
    }

    unordered_map<int, int> cost;
    rep(i, n){
        balance[i + 1] = balance[i] + L[i];
        int curr_balance = balance[i + 1];
        if (!cost[curr_balance]) cost[curr_balance] = i + 1;
    }
    
    // 2. Solo izq
    int ans = 1e9;
    for(const auto& [bal, costo] : cost){
        if (bal == delta) ans = min(ans, costo);
    }

    // 3. Solo der
    int R_bal = 0;
    rep(i, n){
        R_bal += R[i];
        if (R_bal == delta) ans = min(ans, i + 1);
        if (cost.count(delta - R_bal)) ans = min(ans, i + 1 + cost[delta - R_bal]);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}