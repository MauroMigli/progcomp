#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)


int main(){
    int n, m; cin >> n >> m;
    vector<string> A(n);
    rep(i, n) cin >> A[i];

    int limit_row = n - 8;
    int limit_col = m - 8;

    rep(i, limit_row){
        rep(j, limit_col){
            bool check = true;

            rep(p, 3){
                rep(q, 3){
                    if (A[i + p][j + q] != '#'){
                        check = false;
                        break;
                    }
                    if (A[i + 6 + p][j + 6 + q] != '#'){
                        check = false;
                        break;
                    }
                    if (!check) break;
                }
            }
            
            rep(p, 4){
                if (A[i + 3][j + p] != '.'){
                    check = false;
                    break;
                }
                if (A[i + p][j + 3] != '.'){
                    check = false;
                    break;
                }
                if (A[i + 5][j + 8 - p] != '.'){
                    check = false;
                    break;
                }
                if (A[i + 8 - p][j + 5] != '.'){
                    check = false;
                    break;
                }

                if (!check) break;
            }
            if (check) cout << i + 1 << ' ' << j + 1 << endl;
        }
    }

    return 0;
}