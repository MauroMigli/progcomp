#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repf(i, k, n) for (int i = k; i < (n); i++)

void solve(){
    int n, x_1, x_2, k; cin >> n >> x_1 >> x_2 >> k;

    if (n == 2 || n == 3) {
        cout << 1 << endl;
        return;
    }

    int d = abs(x_2 - x_1);
    d = min(d, n - d);
    cout << d + k << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();

    return 0;
}