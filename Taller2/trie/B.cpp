#include<bits/stdc++.h> 
using namespace std;
#define rep(i, n) for(int i = 0; i < n: i++)

void solve(){
    string s, t; cin >> s >> t;

    int j = 0;

    rep(i, s.size()){
        if (s[i] == t[j] || s[i] == '?'){
            j++;
        }

        if (j == t.size()){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int T; cin >> T;
    while(T--) solve();
    
    return 0;
}