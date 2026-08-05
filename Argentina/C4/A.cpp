#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    
    int idx_max = -1;
    int maxi = 0;
    vector<int> A(n); rep(i, n) {
        cin >> A[i];
        if (A[i] >= maxi){
            maxi = A[i];
            idx_max = i;
        }
    }
    
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