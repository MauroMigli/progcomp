#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

void solve() {
    string s; cin >> s;
    // string mi_substr(size_t pos = 0, size_t len = x) const;

    int ans = 0;
    string curr_num = "";
    string curr_decimals = "";
    
    int start = 0;
    rep(i, (int)s.size()){
        if (is_digit(s[i]) && !start){
            curr_num += s[i];
            start = 1;
        }
        if (start && !is_digit(s[i])) {
            ans += stoi(curr_num);
            curr_num = "";
        }
        if (s[i] == '.'){
            start = 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}