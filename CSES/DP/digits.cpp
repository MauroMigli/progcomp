#include<bits/stdc++.h>
using namespace std;

vector<int> memo;

int dp(int n){
    if (memo[n] != -1) return memo[n];
    if (n == 0) return memo[n] = 0;
    string s = to_string(n);

    int ans = 1e8;

    for(int i = 0; i < s.size(); i++){
        int dig = s[i] - '0';
        if (dig == 0) continue;

        ans = 1 + min(ans, dp(n - dig));
    }

    return memo[n] = ans;
}

void solve(){
    int n; cin >> n;
    memo.assign(n + 1, -1);
    string s = to_string(n);

    cout << dp(n) << endl;
}
int main(){
    int t=1;
    while(t--) solve();
}