#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    vector<ll> A(n); 
    rep(i, n) cin >> A[i];

    int ans = 0;
    repk(i, 1, n){
        if (A[i] >= A[i - 1]) continue;
        ll dif = A[i - 1] - A[i];
        bitset<32> bin(dif);
        
        int highest;
        rep(j, 32){
            if (bin[j]){
                highest = j + 1;
                A[i] += (1 << j);
            }
        }
        ans = max(ans, highest);
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