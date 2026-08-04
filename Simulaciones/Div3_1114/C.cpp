#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int even_a = 0, even_b = 0;
    int odd_a = 0, odd_b = 0;
    rep(i, n){
        even_a += (i % 2 == 0 && a[i] == '1');
        odd_a += (i % 2 == 1 && a[i] == '1');

        even_b += (i % 2 == 0 && b[i] == '1');
        odd_b += (i % 2 == 1 && b[i] == '1');
    }

    if (even_a == even_b && odd_a == odd_b) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}