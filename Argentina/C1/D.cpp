#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    int sum = 0;
    vector<int> A(n); rep(i, n) {
        cin >> A[i];
        sum += A[i];
    }
    sort(A.begin(), A.end());
    
    vector<vector<int>> divisors(n);
    repk(d, 1, 101){
        rep(j, n){
            if (A[j] % d == 0) divisors[j].push_back(d);
        }
    }

    int mini = sum;
    rep(i, n - 1){
        for(int d : divisors[n - i - 1]){
            mini = min(mini, A[0] * (d - 1) + A[n - i - 1] / d - A[n - i - 1] + sum);
        }
    }
    cout << mini << endl;
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