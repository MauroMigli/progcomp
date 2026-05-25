#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for(int i = 0; i < n; i++)


int euclid_distance(p x_1, p x_2){
    return (x_1.first - x_2.first)  * (x_1.first - x_2.first)  + (x_1.second - x_2.second) * (x_1.second - x_2.second);
}

int main(){
    int n, D; cin >> n >> D;
    vector<pair<int, int>> A(n);
    rep(i, n) cin >> A[i].first >> A[i].second;


    vector<int> infected = {0};
    set<int> s;
    s.insert(0);
    vector<string> ans(n, "No");
    ans[0] = "Yes";

    while(infected.size() != n){
        int m = infected.size();
        bool gained = false;
        rep(j, m){
            rep(i, n){
                if (i == j) continue; 
                if (euclid_distance(A[i], A[infected[j]]) <= D * D && !s.count(i)){
                    infected.push_back(i);
                    ans[i] = "Yes";
                    s.insert(i);
                    gained = true;
                    m++;
                }
            }
        }
        if (!gained) break;
    }
    for(string s : ans) cout << s << endl;

    return 0;
}