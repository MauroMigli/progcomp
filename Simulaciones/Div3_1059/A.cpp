#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repf(i, k, n) for (int i = k; i < (n); i++)

const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> A(n);

    int maximo = 0;
    rep(i, n) {
        cin >> A[i];
        maximo = max(maximo, A[i]);
    }
    cout << maximo << '\n';
    
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
