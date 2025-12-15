#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
ll MOD = 1e9 + 7;

vector<ll> memo;

ll dp(int n){
    if (n < 0) return 0;
    
    if (memo[max(n, 0)] != -1) 
        return memo[n];
    if (n == 0) return memo[n] = 1;
    
    return memo[n] = (
        dp(n - 1) % MOD + dp(n - 2) % MOD + dp(n - 3) % MOD +
        dp(n - 4) % MOD + dp(n - 5) % MOD + dp(n - 6) % MOD
    ) % MOD;
}

int main(){
    int n; cin >> n;
    memo.resize(n + 1, -1);
    cout << dp(n) << endl;
    
    return 0;
}