#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q; cin >> q;

    while(q--){
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;

        int a = l1;
        int b;
        if (l2 != a) b = l2;
        else b = r2;
        cout << a << " " << b << endl;
    }

    return 0;
}