#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

struct Point {
    int x;
    int y;
    Point(int x_, int y_){
        x = x_;
        y = y_;
    }
};

int main(){
    int W, H; cin >> W >> H;
    int n; cin >> n;
    vector<pair<Point, Point>> A;
    
    rep(i, n){
        int x_1, y_1, x_2, y_2; cin >> x_1 >> y_1 >> x_2 >> y_2;
        Point p_1 = Point(x_1, y_1);
        Point p_2 = Point(x_2, y_2);

        if ()
    }
    
}