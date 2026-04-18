#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)

int main(){
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> chars;

    char prev = s[0];
    int largo = 1;
    chars[s[0]] = 1;

    repk(i, 1, n){
        if (prev == s[i]){
            largo++;
            if (chars[s[i]] < largo) chars[s[i]]++;
        } else {
            if (chars.find(s[i]) == chars.end()) chars[s[i]] = 1;
            largo = 1;
        }
        prev = s[i];
    }


    int ans = 0;
    for(auto [c, i] : chars){
        ans += i;
    }
    cout << ans << endl;
    return 0;
}