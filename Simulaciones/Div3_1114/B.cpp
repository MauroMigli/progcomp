#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

void solve(){
    int n;  cin >> n;
    string s; cin >> s;

    string s_prime = "";
    s_prime += s[0];
    
    bool just_one = false;
    int length = 1;
    repk(i, 1, n){
        if (s[i] != s[i - 1]){
            if (!just_one && i - 1 != 0 && length == 1){
                just_one = true;
            }
            s_prime += s[i];
            length = 1;
        } else length++;
    }
    

    int ans = (int)s_prime.size();
    repk(i, 2, n){
        if (s[i - 2] == s[i] && s[i - 1] != s[i]){
            cout << ans - 2 << endl; 
            return;
        }
    }
    
    if (just_one) cout << ans - 1 << endl;
    else cout << (int)s_prime.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}