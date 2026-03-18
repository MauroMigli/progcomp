#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> A(n);
    vector<int> idx_of(n + 1);
 
    rep(i, n){
        cin >> A[i];
        idx_of[A[i]] = i;
    }
    int ans = 1;
    repk(i, 2, n + 1){
        if (idx_of[i] < idx_of[i - 1]){
            ans++;
        }
    }
    
    rep(j, m) {
        int a, b; cin >> a >> b; a--; b--;

        if (a == b) cout << ans << endl;
        else {
            // Ver parte izq
            set<pair<int, int>> affected;

            if (A[a] > 1) affected.insert({A[a] - 1, A[a]});
            if (A[a] < n) affected.insert({A[a], A[a] + 1});
            if (A[b] > 1) affected.insert({A[b] - 1, A[b]});
            if (A[b] < n) affected.insert({A[b], A[b] + 1});
            

            
           
            for(auto [x, y]: affected){
                if (idx_of[y] < idx_of[x]) ans--;
            }

            swap(A[a], A[b]);
            swap(idx_of[A[b]], idx_of[A[a]]);
            
            for(auto [x, y]: affected){
                if (idx_of[y] < idx_of[x]) ans++;
            }
            // print
            cout << ans << endl;            
        }
    }
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