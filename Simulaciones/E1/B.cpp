#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)


int main(){
    int n; cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    sort(A.begin(), A.end(), greater<int>());
    
    int prev = A[0];
    repk(i, 1, n){
        if (A[i] != prev){
            cout << A[i] << endl;
            return 0;
        }
    }

    return 0;
}