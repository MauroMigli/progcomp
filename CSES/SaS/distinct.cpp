#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define rep(i, n) for(int i = 0; i < n; i++)

void solve() {
    int n; cin >> n;
    set<int> s;
    rep(i, n){
        int x; cin >> x;
        s.insert(x);
    }
    cout << s.size() << "\n";
}

int main() {
    fastio()
    int t = 1; // Change to cin >> t; if multiple test cases
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}