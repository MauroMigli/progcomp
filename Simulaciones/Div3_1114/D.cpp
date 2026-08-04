#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i, k, n) for (ll i = (ll)(k); i < (ll)(n); ++i)

void solve(){
    ll n; cin >> n;
    map<ll, ll> freqs;
    unordered_map<ll ,vector<ll>> indices;
    rep(i, n){
        ll b; cin >> b;
        freqs[b]++;
        indices[b].push_back(i);
    }

    
    vector<ll> A(n);
    p prev = *freqs.begin();
    ll candidato = 0;
    
    if (prev.first != 0) {
        cout << -1 << endl;
        return;
    }

    for(auto it = next(freqs.begin()); it != freqs.end(); it++){
        auto [num, freq] = *it;

        if ((num - prev.first) % prev.second == 0){
            if ((num - prev.first) / prev.second <= candidato){
                cout << -1 << endl;
                return;
            }
            
            candidato = (num - prev.first) / prev.second;
            for(int idx : indices[prev.first]){
                A[idx] = candidato;
            }
        } else {
            cout << -1 << endl;
            return;
        }
        prev.first = num; prev.second = freq;
    }

    for(int idx : indices[prev.first]){
        A[idx] = candidato + 1;
    }
    


    rep(i, n) cout << A[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}