#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)

int main(){
    int m; cin >> m;
    vector<int> A(m);
    vector<int> prefix(m + 1);
    
    int total_days = 0;
    rep(i, m) {
        cin >> A[i];
        total_days += A[i];
        prefix[i + 1] = total_days;
    }

    // Prefix sum tells us how many days have passed at month i
    int mid_day = (total_days + 1) / 2;
    int l = 0, r = m;
    int mid;
    while(l < r){
        mid = l + (r - l) / 2;
        if (prefix[mid] >= mid_day)
            r = mid;
        else 
            l = mid + 1;
    }

    cout << l << " " << mid_day - prefix[l - 1] << endl;


    return 0;
}