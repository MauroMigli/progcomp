#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    string num; cin >> num;
    vector<int> f(10);
    rep(i, 9){
        cin >> f[i + 1];
    }

    bool activar = false;
    rep(i, n){
        if (f[num[i] - '0'] > num[i] - '0' && !activar){
            activar = true;
            num[i] = (char)(f[num[i] - '0'] + '0');
        } else if (f[num[i] - '0'] >= num[i] - '0' && activar) {
            num[i] = (char)(f[num[i] - '0'] + '0');
        } else if (f[num[i] - '0'] < num[i] && activar){
            break;
        } else if (f[num[i] - '0' <= num[i] && !activar]){
            continue;
        }
    }
    cout << num << endl;
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