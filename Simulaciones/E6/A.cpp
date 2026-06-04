#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

char to_hexa(int n){
    if (n == 10) return 'A';
    if (n == 11) return 'B';
    if (n == 12) return 'C';
    if (n == 13) return 'D';
    if (n == 14) return 'E';
    if (n == 15) return 'F';
    else return n + '0';
}

int main(){
    int n; cin >> n;

    cout << to_hexa(n / 16) << to_hexa(n % 16) << endl;
    
    return 0;
}