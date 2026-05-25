#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n; cin >> n;
    vector<pair<string, int>> A(n);
    
    int min_edad = 1e9 + 1;
    int idx = -1;
    rep(i, n) {
        cin >> A[i].first >> A[i].second;
        if (min_edad > A[i].second){
            min_edad = A[i].second;
            idx = i;
        }
    }

    rep(i, n){
        cout << A[(i + idx) % n].first << endl;
    }

    return 0;
}