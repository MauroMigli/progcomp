#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n; cin >> n;
    int max_a = -1;
    vector<int> A(n); rep(i, n) {
        cin >> A[i];
        max_a = max(max_a, A[i]);
    }
    sort(A.begin(), A.end());
    int current = A[0];

}