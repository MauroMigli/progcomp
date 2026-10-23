#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

int n;
vector<int> A;

bool se_puede_con(ll init){
    rep(i, n){
        init += A[i];
        if (init < 0) return false;
    }
    return true; 
}

void solve() {
    ll total_sum = 0;
    cin >> n;
    A.assign(n, 0); rep(i, n) {
        cin >> A[i];
        total_sum += A[i];
    }
    ll l = 0, r = 1e15;
    ll mid;

    while(l < r){
        mid = l + (r - l) / 2;

        if (se_puede_con(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l + total_sum << '\n';
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