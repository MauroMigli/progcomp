#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string n; cin >> n;
    int size = n.size();


    for(int i = 0; i < size; i++){
        if (i >= 3) n[i] = '0';
    }
    cout << n << endl;
    
    return 0;
}