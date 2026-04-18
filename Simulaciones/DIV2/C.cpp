#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


void solve(){
    int n; cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    int b;
    rep(i, n) cin >> b;
    
    int ans = 0;
    rep(i, n){
        if (i == 0){
            if (gcd(A[i], A[i + 1]) != A[i]){
                ans++;
            }
        } else if (i == n - 1){
            if (gcd(A[i], A[i - 1]) != A[i]){
                ans++;
            }
        }
        else {
            int gcd_left = gcd(A[i], A[i - 1]);
            int gcd_right = gcd(A[i], A[i + 1]);
            int gcd_all = (gcd_left, A[i + 1]);


            if (gcd(gcd_all, A[i - 1]) != 1 && gcd(gcd_all, A[i + 1])){
                if (max(gcd_right, gcd_left) != A[i]) ans++;
            }
        }
    }
    cout << ans << endl;
}


int main(){
    int t; cin >> t;
    while(t--) solve();

    
    return 0;
}