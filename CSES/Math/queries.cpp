#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)



void solve(){
    int n, k; cin >> n >> k;

    if (k <= n / 2){
        cout << 2 * k << endl;
        return;
    }

int main(){
    int q; cin >> q;

    while(q--) solve();
    
    return 0;
}