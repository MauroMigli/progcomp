#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main(){
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> stones(m);
    rep(i, m){
        cin >> stones[i].first;
    }
    rep(i, m){
        cin >> stones[i].second;
    }
    
    sort(stones.begin(), stones.end());
    vector<pair<ll, ll>> intervalos;
    int l = 0, r = 0;
    for(int i = 1; i < m; i++){
        if (stones[i].first == stones[i - 1].first + 1) r++;
        else {
            intervalos.push_back({l, r});
            l = stones[i].first;
            r = l;
        }
    }
    intervalos.push_back({n + 1, n + 1});
    int j = 0;
    ll extra = 0;
    rep(i, m){
        bool in_interval = intervalos[j].first < stones[i].first && stones[i].first < intervalos[j].second;
        if (in_interval){
            extra += stones[i].second - 1;
        } else {
            ll gap = stones[i].first - stones[i - 1].first - 1;
            if (extra < gap){
                cout << -1 << endl;
                return 0;
            }

            extra -= gap;
            j++;
        }
    }

    ll final_gap = n - stones[m - 1].first;
    if (final_gap < )

    return 0;
}