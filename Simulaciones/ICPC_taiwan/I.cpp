#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repf(i, k, n) for(int i = k; i < n; i++)
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


vector<int> B;
stack<int> st;
int n;
int full_mask;
vector<vector<int>> dp;


bool backtrack(int mask, int prev){
    if (dp[mask][prev] != -1) return dp[mask][prev];
    if (mask == full_mask) return dp[mask][prev] = true;

    rep(i, n - 1){
        if ((mask & (1 << i)) == 0){

            if (B[i] % st.top() == 0 && B[i] / st.top() <= 100){
                st.push(B[i] / st.top());
                if (backtrack(mask | (1 << i), st.top())) return dp[mask][prev] = true;
                else st.pop();
            }
        }
    }

    return dp[mask][prev] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    full_mask = (1 << (n - 1)) - 1;

    dp.assign(1 << (n - 1), vector<int>(101, -1));
    B.assign(n - 1, 0);
    rep(i, n - 1) cin >> B[i];

    rep(i, n - 1){
        repf(a_1, 1, 101){
            if (B[i] % a_1 == 0 && a_1 <= 100 && B[i] / a_1 <= 100){
                st.push(a_1);
                st.push(B[i] / a_1);

                if (backtrack(1 << i, B[i] / a_1)){
                    cout << "Yes" << endl;
                    
                    while(!st.empty()){
                        cout << st.top() << " ";
                        st.pop();
                    }
                    cout << endl;
                    return 0;
                } else {
                    st.pop(); st.pop();
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}