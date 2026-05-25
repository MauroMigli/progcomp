#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    int curr = 0;
    rep(i, n){
        if (s[i] == 'a'){
            curr++;
        } else {
            if (curr > 1) ans += curr;
            curr = 0;
        }
    }
    if (curr > 1) ans += curr;
    cout << ans << endl;
    
    return 0;
}