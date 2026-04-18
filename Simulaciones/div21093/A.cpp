#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

void solve(){
    int n; cin >> n;
    vector<int> A(n); rep(i, n) cin >> A[i];

    sort(A.begin(), A.end(), greater<int>());
    for(int i = 1; i < n; i++){
        if (A[i] == A[i - 1]){
            cout << -1 << endl;
            return;
        }
    }
    rep(i, n) cout << A[i] << " ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}