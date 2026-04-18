#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)
typedef long long ll;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> A(n); rep(i, n) cin >> A[i];

    int max_same_count = 1;
    int current_same_count = 1;
    int l;
    int current_l;
    bool first_seq = true;
    int first_same_count = 1;
    repk(i, 1, n){
        if (first_seq){
            if (A[i] == A[i - 1]) first_same_count++;
            else {
                first_seq = false;
                current_l = i;
                l = i;
            }
        }
        
        if (A[i] == A[i - 1]){
            current_same_count++;
            if (current_same_count > max_same_count){
                max_same_count = current_same_count;
                l = current_l;
            }
        } else {
            current_l = i;
        }
    }

    if (m - A[0] < first_same_count){
        cout << "NO" << endl;
        return;
    
    if (m - 1 < max_same_count){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}