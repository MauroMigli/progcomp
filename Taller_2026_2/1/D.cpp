#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
typedef vector<vector<ll>> matrix;
ll MOD = 998244353;

matrix multiply_matrices(const matrix& A, const matrix& B){
    int n = (int)A.size();
    int m = (int)B[0].size();
    int p = (int)A[0].size();

    matrix C(n, vector<ll>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < p; k++) {
            for (int j = 0; j < m; j++) {
                ll sumando = (A[i][k] % MOD) * (B[k][j] % MOD);
                C[i][j] = (C[i][j] +  sumando % MOD) % MOD;
            }
        }
    }
    
    return C;
}

matrix identity(ll n){
    matrix I(n, vector<ll>(n));

    rep(i, n){
        I[i][i] = 1;
    }
    return I;
}

matrix bin_pow_matrix(matrix& A, ll n){
    int size = (int)A.size();
    matrix ans = identity(size);

    while(n > 0){
        if (n & 1) ans = multiply_matrices(ans, A);

        A = multiply_matrices(A, A);
        n >>= 1;
    }
    return ans;
}

void solve() {
    ll n; cin >> n;
    if (n == 0) {
        cout << 0 << '\n';
        return;
    }
    if (n == 1){
        cout << 1 << '\n';
        return;
    }

    matrix A = {{1, 1}, {1, 0}};
    matrix exp = bin_pow_matrix(A, n - 2);
    cout << (exp[0][0] + exp[0][1]) % MOD << '\n';
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