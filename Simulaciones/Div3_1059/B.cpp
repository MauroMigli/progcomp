#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repf(i, k, n) for (int i = k; i < (n); i++)

const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    vector<int> indices;
    rep(i, n){
        if (s[i] == '0'){
            indices.push_back(i + 1);
        }
    }
    cout << indices.size() << '\n';
    for(int idx : indices) cout << idx << " ";
    cout << endl;
}

int main() {
    fastio;
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
