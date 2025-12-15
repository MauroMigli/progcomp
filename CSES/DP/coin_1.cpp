#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repf(i, k, n) for (int i = k; i < n; i++)


int MOD = 1e9 + 7;

int main(){
    int n, x; cin >> n >> x;

    vector<int> dp(x + 1, 0);
    vector<int> C(n);


    rep(i, n) cin >> C[i];

    dp[0] = 1;

    rep(i, x + 1){
        if (dp[i] != 0){
            for (int c : C){
                if (i + c <= x) 
                    dp[i + c] = (dp[i + c] + dp[i]) % MOD;
            }
        }
    }
    
    cout << dp[x] << endl;

    return 0;
}