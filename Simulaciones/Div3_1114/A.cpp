#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if (a == b || a == c || b == c){
        cout << 0 << endl;
        return;
    }

    vector<int> A(3);
    A[0] = a; A[1] = b; A[2] = c;
    sort(A.begin(), A.end());

    int dif_max = A[2] - A[1];
    int dif_min = A[1] - A[0];
    cout << min(dif_max, dif_min) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    while(t--) solve();

    return 0;
}