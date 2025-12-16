#include<bits/stdc++.h> 
using namespace std;

void solve(){
    string s; cin >> s;
    if (s.size() > 10){
        s = s[0] + to_string((int)s.size() - 2) + s[s.size() - 1];
    }
    cout << s << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}