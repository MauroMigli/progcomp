#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n, q; cin >> n >> q;
    vector<vector<int>> A(n);
    rep(i, n) {
        int L; cin >> L;
        A[i].assign(L, 0);
        rep(j, A[i].size()){
            cin >> A[i][j];
        }
    }

    while(q--){
        int s, t; cin >> s >> t; s--; t--;
        cout << A[s][t] << endl;
    }
    return 0;
}