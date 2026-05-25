#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    vector<int> N(8);
    rep(i, 8) {
        cin >> N[i];
        if (N[i] == 9) {
            cout << "F" << endl;
            return 0;
        }
    }
    cout << "S" << endl;
    return 0;
}