// https://cses.fi/paste/bd0f17120870b47eeae705/
/*
    Here we can observe that for every complete square the numbers in it will be n^2 , now for the next row or col wwe can calculate based on observation 
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> y >> x;
        long long ans = 0;
        if(x > y) {
            ans += 1LL * (x-1) * (x-1) ;
            ans += ((x&1) ? x - 1 + x - y + 1: y);
        } else {
            ans += 1LL * (y-1) * (y-1) ;
            ans += ((y&1) ? x : y - 1 + y - x + 1);
        }
        cout << ans << "\n";
    }
}