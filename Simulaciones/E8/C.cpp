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
   
    ll r = stones[m - 1].first;
    for(int i = m - 1; i >= 0; i--){
        ll l = stones[i].first;

    }

    return 0;
}