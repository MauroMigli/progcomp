#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
int INF = 1e9;

vector<int> memo;

int dp(int i){
    if (memo[i] != -1) return memo[i];
    if (i == 0) return 0;

    int min_steps = INF;
    int i_copy = i;
    while (i_copy != 0){
        int dig = i_copy % 10;
        if (dig != 0) min_steps = min(min_steps, dp(i - dig) + 1);
        i_copy /= 10;
    }
    return memo[i] = min_steps;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    memo.assign(n + 1, -1);

    cout << dp(n) << '\n';

    return 0;
}