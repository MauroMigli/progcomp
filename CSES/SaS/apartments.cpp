#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define rep(i, n) for(int i = 0; i < n; i++)

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> A(n), B(m);
    
    rep(i, n)
        cin >> A[i];
    rep(j, m)
        cin >> B[j];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0, j = 0, count = 0;
    while(i < n && j < m){
        if (abs(A[i] - B[j]) <= k){
            count++;
            i++;
            j++;
        }
        else if (A[i] - B[j] > k) j++;
        else i++;
    }
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