#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<int> cuadrados(1e3 + 1);

void generar_cuadrados(){
    for(int i = 1; i * i <= 1e6; i++){
        cuadrados[i] = i * i;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    generar_cuadrados();
    // acercarse al cuadrado mas similar

    int A; cin >> A;

    int a = 0;
    rep(i, 1e3 + 1){
        if (cuadrados[i] > A) break;
        a = i;
    }

    int area_cuadrado = cuadrados[a];
    
    int diferencia = A - area_cuadrado;

    int ans = 4 * a;
    if (diferencia == 0){
        ans += 0;
    }
    else if (diferencia <= a){
        ans += 2;
    }
    else ans += 4;

    cout << ans << endl;
    return 0;
}