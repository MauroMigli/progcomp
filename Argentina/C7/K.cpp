#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n, k; cin >> n >> k;
    
    vector<int> summer_sizes;

    int ans = 0;
    vector<int> A(n); rep(i, n) {
        int a; cin >> a;
        A[i] = a >= 0;
        if (!A[i]) k--;
    }
    
    // Caso 1: No hay suficientes dias
    if (k < 0) {
        cout << -1 << endl;
        return;
    }

    int start = 0;
    rep(i, n){
        if (A[i] >= 0) start++;
        else break;
    }
    repk(i, start, n){

    }
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