#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)




int main(){
    int H, W; cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));
    
    map<int, int> freq_A, freq_B;
    rep(i, H) rep(j, W) {
        cin >> A[i][j]; // -> num
        freq_A[A[i][j]]++;
    }
    rep(i, H) rep(j, W) {
        cin >> B[i][j];
        freq_B[B[i][j]]++;
    }

    if(freq_A != freq_B){
        cout << -1 << endl;
        return 0;
    }

    

    return 0;
}