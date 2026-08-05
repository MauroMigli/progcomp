#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    vector<vector<int>> daughter(n);
    vector<bool> used_prince(n, 0);
    vector<bool> used_daughter(n, 0);

    rep(i, n){
        int k; cin >> k;
        daughter[i].assign(k, 0);
        rep(j, k) {
            cin >> daughter[i][j]; daughter[i][j]--;
        }
    }


    int daughter_idx = -1;
    rep(i, n){
        rep(j, (int)daughter[i].size()){
            int g = daughter[i][j];
            if (!used_prince[g]) {
                used_prince[g] = true;
                used_daughter[i] = true;
                break;
            }
        }
        if (!used_daughter[i]) daughter_idx = i;
    }
    
    
    int prince_idx = -1;
    rep(i, n){
        if (!used_prince[i]) {
            prince_idx = i;
            break;
        }
    }

    if (prince_idx != -1 && daughter_idx != -1){
        cout << "IMPROVE" << '\n';
        cout << daughter_idx + 1 << ' ' << prince_idx + 1 << endl;
    } else cout << "OPTIMAL" << endl;
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