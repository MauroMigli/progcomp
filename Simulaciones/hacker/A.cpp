#include<bits/stdc++.h>
using namespace std;

void solve(int t){
    int n, m; cin >> n >> m;

    if (m > n) {
        cout << "Case #" << t << ": NO" << endl;
    }
    else if (n - m <= m - 2){
        cout << "Case #" << t << ": YES" << endl;
        
    }
    else if (n % 2 == 0){
        cout << "Case #" << t << ": YES" << endl;
    }
    else cout << "Case #" << t << ": NO" << endl;
}

int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    
    return 0;
}