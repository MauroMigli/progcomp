#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int to_points(int x){
    if (x > 10) return 10;
    return x;
}

int main(){
    int n; cin >> n;
    map<int, int> cartas;
    rep(i, 13){
        cartas[i + 1] = 4;
    }

    int J_1, J_2; cin >> J_1 >> J_2;
    int M_1, M_2; cin >> M_1 >> M_2;
    cartas[J_1]--; cartas[M_1]--;
    cartas[J_2]--; cartas[M_2]--;

    int J = to_points(J_1) + to_points(J_2);
    int M = to_points(M_1) + to_points(M_2);

    rep(i, n) {
        int I; cin >> I;
        cartas[I]--;
        J += to_points(I);
        M += to_points(I);
    }

    int naive = min(24 - J, 23 - M);
    
    for(int i = naive; i <= 13; i++){
        if (cartas[i] > 0){
            if ((J + to_points(i) > 23 && M + to_points(i) <= 23) || M + to_points(i) == 23){
                cout << i << endl;
                return 0;
            }
        }
    }
    
    cout << -1 << endl;


    return 0;
}