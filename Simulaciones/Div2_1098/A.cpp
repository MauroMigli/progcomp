#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repf(i, k, n) for (int i = k; i < (n); i++)

void solve(){
    int n; cin >> n;

    vector<int> w(n);
    
    int zero = 0;
    int one = 0;
    int two = 0;
    rep(i, n){
        cin >> w[i];
        zero += w[i] == 0;
        one += w[i] == 1;
        two += w[i] == 2;
    }

    int ans = zero + min(one, two);
    if (two - one >= 3) ans += (two - one) / 3;
    else if (one - two >= 3) ans += (one - two) / 3;

    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();

    return 0;
}