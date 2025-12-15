#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repf(i, k, n) for (int i = k; i < (n); i++)

void solve(){
    int n; cin >> n;

    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    else if (n == 3) {
        cout << "1 3" << '\n' << "2 3" << endl;
        return;
    } else if (n == 4){
        cout << "1 2" << '\n' << "3 1" << '\n' << "4 1" << endl;
        return;
    } else if (n == 5){
        cout << "1 4" << '\n' << "1 5" << '\n' << "5 2" << '\n' << "2 3" << endl;
        return;
    } else if (n == 6){
        cout << "6 1" << '\n' << "1 2" << '\n' << "2 5" << '\n' << "2 3" << '\n' << "3 4" << endl;
        return;
    }

    rep(i, n){
        if (i + 1 != n - 4 && i + 1 != 2){
            cout << "2 " << i + 1 << '\n';
        }
    }
    cout << "1 " << n - 4 << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}