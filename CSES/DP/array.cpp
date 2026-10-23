#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
int M = 1e9 + 7;

int n, m;
vector<int> A;
vector<vector<int>> memo;

bool in_range(int x) {
    return 1 <= x && x <= m;
}

int dp(int i, int prev){
    if (i == n) return 1;
    if (memo[i][prev] != -1) return memo[i][prev];
    
    if (A[i] == 0){
        int count = 0;
        for (int dx : {-1, 0, 1}){
            if (in_range(prev + dx)){
                count = (count + dp(i + 1, prev + dx)) % M;
            }
        }
        return memo[i][prev] = count;
    } else if (abs(A[i] - prev) > 1) return memo[i][prev] = 0;
    else return memo[i][prev] = dp(i + 1, A[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;
    A.assign(n, 0); 
    memo.assign(n, vector<int>(m + 1, -1));
    rep(i, n) cin >> A[i];

    if (A[0] != 0)cout << dp(0, A[0]) << '\n';
    else {
        int count = 0;
        rep(j, m){
            count = (count + dp(1, j + 1)) % M;
        }
        cout << count << '\n';
    }

    return 0;
}