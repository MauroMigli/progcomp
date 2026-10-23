#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

int n;
ll suma;

bool backtracking(int i, vector<ll>& largos, vector<ll> A){
    if (i == n){
        rep(j, 3){
            if (largos[j] != largos[j + 1]){
                return false;
            }
        }
        return true;
    }

    bool ans = false;
    rep(j, 4){
        if (largos[j] + A[i] > suma) continue;
        largos[j] += A[i];
        ans = ans || backtracking(i + 1, largos, A);
        largos[j] -= A[i];
    }
    return ans;
}

void solve() {
    cin >> n;
    suma = 0;

    vector<ll> A(n); rep(i, n) {
        cin >> A[i];
        suma += A[i];
    }

    if (suma % 4 != 0) {
        cout << "NO\n";
        return;
    }

    suma /= 4;
    vector<ll> largos(4, 0);

    if (backtracking(0, largos, A)) cout << "SI\n";
    else cout << "NO\n";
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