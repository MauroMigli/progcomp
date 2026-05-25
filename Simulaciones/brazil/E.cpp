#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n; cin >> n;
    vector<int> H(n);
    vector<int> used(n, 0);
  

    int max_h = 0;
    rep(i, n) {
        cin >> H[i];
        max_h = max(H[i], max_h);
    }
    vector<set<int>> idxs(max_h + 1); 

    rep(i, n) idxs[H[i]].insert(i);

    int ans = 0;
    rep(i, n){
        if (used[i]) continue;

        int idx = i;
        bool stop = false;
        while(!stop){
            idxs[H[idx]].erase(idx);
            used[idx] = 1;
            
            auto it = idxs[H[idx] - 1].lower_bound(idx);
            if (idxs[H[idx] - 1].empty() || it == idxs[H[idx] - 1].end()) stop = true;
            else idx = *it;
        }
        ans++;
    }
    cout << ans << endl;


    return 0;
}