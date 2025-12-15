#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
ll MOD = 1e9 + 7;
ll INF = 1e9;

vector<int> C;
vector<int> memo;

int dp(int y){    
    if (memo[y] != -1) return memo[y];
    if (y == 0) return 0;
    
    memo[y] = INF;
    rep(i, C.size()){
        if (y - C[i] >= 0) {
            memo[y] = min(memo[y], 1 + dp(y - C[i]));
        }
    }
    
    return memo[y]; 
}

int main(){
    int n, x; cin >> n >> x;
    C.resize(n);
    rep(i, n) cin >> C[i];
    memo.resize(x + 1, -1);
    
    dp(x);
    if (memo[x] == INF) cout << -1 << endl;
    else cout << memo[x] << endl;

    return 0;
}