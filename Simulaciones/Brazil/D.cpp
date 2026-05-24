#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y; cin >> n >> x >> y;
    int pot_2 = (1 << n);
    int l = 0, r = pot_2, d = 0, u = pot_2;
    int mid_x = (l + r) / 2;
    int mid_y = (u + d) / 2;
    int movs = -1;

    while(mid_x != x || mid_y != y){
        mid_x = (l + r) / 2;
        mid_y = (u + d) / 2;

        if (x < mid_x) r = mid_x;
        else l = mid_x;

        if (y < mid_y) u = mid_y;
        else d = mid_y;

        movs++;
    }

    cout << max(0, movs) << endl;

    return 0;
}