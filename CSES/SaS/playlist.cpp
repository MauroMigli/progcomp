#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    map<int, int> last_idx;
    int ans = 0;

    for(int i = 0, j = 0; i < n; i++){
        cin >> A[i];

        j = max(last_idx[A[i]], j);
        ans = max(ans, i - j + 1);

        last_idx[A[i]] = i + 1;
    }

    cout << ans << endl;
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