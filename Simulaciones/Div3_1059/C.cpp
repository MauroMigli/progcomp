#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll MOD = 1e9 + 7;
// string bin = bitset<32>(n).to_string();

void solve(){
    int a, b; cin >> a >> b;
    string A = bitset<32>(a).to_string();
    string B = bitset<32>(b).to_string();

    A.erase(0, A.find_first_not_of('0'));
    B.erase(0, B.find_first_not_of('0'));

    if (B.size() > A.size()){
        cout << -1 << endl;
        return;
    }

    string A2 = bitset<32>(a).to_string();
    string B2 = bitset<32>(b).to_string();

    vector<ll> xs;
    rep(i, 32){
        if (A2[31 - i] != B2[31 - i]){
            xs.push_back(1<<i);
        }
    }
    cout << xs.size() << endl;
    for(ll x : xs){
        cout << x << " ";
    }
    cout << endl;
    xs.clear();
}
int main() {
    fastio;
    int t; cin >> t;
    while(t--) solve();    

    return 0;
}
