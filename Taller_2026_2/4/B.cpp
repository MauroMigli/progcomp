#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

int n;
ll T;

bool backtracking(int i, ll sum, const vector<ll>& A){
    if (sum == T) return true;
    if (i == n) return false;
    
    return backtracking(i + 1, sum + A[i], A) || backtracking(i + 1, sum, A);
}

void solve() {
    cin >> n >> T;
    vector<ll> A(n); rep(i, n) cin >> A[i];

    if (backtracking(0, 0, A)) cout << "SI\n";
    else cout << "NO\n";
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