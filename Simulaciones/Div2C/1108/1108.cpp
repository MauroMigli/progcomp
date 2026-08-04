#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> prefix_odd(n + 1), prefix_even(n + 1);
    vector<int> A(n); rep(i, n) {
        cin >> A[i];
        if (i % 2){
            prefix_odd[i + 1] = A[i] + prefix_odd[i];
            prefix_even[i + 1] = prefix_even[i];
        } else {
            prefix_even[i + 1] = A[i] + prefix_even[i];
            prefix_odd[i + 1] = prefix_odd[i];
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}