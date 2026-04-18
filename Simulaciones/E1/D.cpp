#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)
#pragma GCC optimize("Ofast")

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<set<int>> has_votes(m + 1);
    vector<int> A(m); rep(i, m) cin >> A[i];

    int maximo = 0;
    multiset<int> ms;
    int ganador = -1;

    rep(i, m){
        ms.insert(A[i]);
        
        if (ms.count(A[i]) > 1)
            has_votes[ms.count(A[i]) - 1].erase(A[i]);
        
        has_votes[ms.count(A[i])].insert(A[i]);


        if (ms.count(A[i]) >= maximo) {
            maximo = ms.count(A[i]);
            ganador = *has_votes[ms.count(A[i])].begin();
        }
        cout << ganador << endl;
    }


    return 0;
}