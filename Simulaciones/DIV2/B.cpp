#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)



void solve(){
    int n; cin >> n;

    vector<int> A(n);
    vector<int> idxof(n+1);
    rep(i, n) {
        cin >> A[i];
        idxof[A[i]] = i;
    }

    vector<int> optimal(n, 0);
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if (i <= idxof[i] + 1) optimal[idxof[i]] = 1;
    }
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + optimal[i - 1];
    }

    int end = n;
    int current_opt = pref[n] - pref[0];
    rep(i, n){
        if (end == i) break;
        if (!optimal[i]){
            if (pref[A[i] - 1] - pref[0] + 1 > current_opt){
                current_opt = pref[A[i] - 1] - pref[0] + 1;
                end = A[i] - 1;
            }
        }
    }

    cout << current_opt << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}