#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)

void solve(){
    int n; cin >> n;
    repk(i, 1, n + 1){
        int q;
        cout << "? " << 2 * i - 1 << " " << 2 * i << endl;
        cin >> q;
        if (q){
            cout << 2 * i - 1 << endl;
            return;
        }
    }

    int q_final;
    cout << "? " << 1 << " " << 3 << endl;
    cin >> q_final;
    if (q_final) cout << 1 << endl;
    else cout << 2 << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}