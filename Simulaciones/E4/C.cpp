#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)


int main(){
    int N, M; cin >> N >> M;
    string s; cin >> s;

    int current_plain = M;
    int max_logo = 0;
    int current_logo = 0;

    rep(i, N){
        int num = s[i] - '0';
        
        if (num == 0){
            current_plain = M;
            current_logo = 0;
        } else if (num == 1){
            if (current_plain > 0) current_plain--;
            else {
                current_logo++;
                max_logo = max(current_logo, max_logo);
            }
        } else {
            current_logo++;
            max_logo = max(current_logo, max_logo);
        }
    }


    cout << max_logo << endl;

    return 0;
}