#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define rep(i, n) for(int i = 0; i < n; i++)

void solve() {
    int n, x; cin >> n >> x;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    sort(A.begin(), A.end());

    int i = 0, j = n - 1;

    int count = 0;
    while(i < j){
        if (A[i] + A[j] <= x){
            i++; j--; count++;
        }
        else {
            j--; count++;
        }
    }
    if (i == j) count++;
    cout << count << endl;
}

int main() {
    fastio()
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}