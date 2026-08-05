#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int curr = 0;

    int maxi = 0;
    rep(i, n){
        if (s[i] == 'X')curr = 0;
        else if (s[i] == 'O'){
            curr++;
            if (curr == k){
                curr = 0;
                maxi++;
            }
        }
    }
    cout << maxi << endl;

    return 0;
}