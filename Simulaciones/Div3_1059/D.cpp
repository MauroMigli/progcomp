#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    int l = 0, r = n - 1;
    int mid;
    int query;
    cout << 2 << " " << l + 1 << " " << r + 1 << endl;
    cin >> query;

    int largo = query - (((n + 1) * n) / 2); 
    int query_normal;
    int query_mod;

    while(l < r){
        mid = l + (r - l)/2;
        
        cout << 1 << " " <<  l + 1 << " " << mid + 1 << endl;
        cin >> query_normal;
        cout << 2 << " " << l + 1 << " " << mid + 1 << endl;
        cin >> query_mod;
        if (query_mod - query_normal > 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << "! " << l + 1 << " " << l + largo << endl;
}

int main() {
    fastio;
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
