#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

void solve(){
    int n; cin >> n;
    vector<int> A(n), B(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];

    int difs = 0;
    int dif_ones = 0;
    int valid_ones = 0;
    rep(i, n){
        if (A[i] != B[i]){
            difs++;
            dif_ones += A[i];
        } else {
            valid_ones += A[i];
        }
    }

    int dif_zeros = difs - dif_ones;
    int valids = n - difs;
    int valid_zeros = valids - valid_ones;


    int even_ones = dif_ones % 2 == 0;
    if (!difs){
        cout << 0 << '\n';
    } else if (even_ones){
        if (dif_ones > 0) cout << 2 << '\n';
        else if (valid_zeros > 0 && valid_ones > 0) cout << 2 << '\n';
        else cout << -1 << '\n';
    } else {
        cout << 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}