#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    
    vector<int> a_even, b_even, a_odd, b_odd;
    rep(i, n){
        bool even = i % 2 == 0;
        if (a[i] == '1'){
            if (even) a_even.push_back(i / 2);
            else a_odd.push_back((i - 1) / 2);
        }
        if (b[i] == '1'){
            if (even) b_even.push_back(i / 2);
            else b_odd.push_back((i - 1)/ 2);
        }
    }

    if (a_even.size() != b_even.size() || a_odd.size() != b_odd.size()){
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    rep(i, (int)a_even.size()){
        ans += abs(a_even[i] - b_even[i]);
    }
    rep(i, (int)a_odd.size()){
        ans += abs(a_odd[i] - b_odd[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--) solve();

    return 0;
}