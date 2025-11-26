// https://cses.fi/paste/40cf709ab68ac9faeb056f/
/*
    We can see that 3 coins are taken out in one go means
        total number of coins should be divisible by 3
    lets take x coins from right and y coins from left in 2 turns
        2x + y = n
        x + 2y = m
        3x = 2n - m
        3y = 2m - n
        x > 0 and y > 0
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << (((n+m)%3 == 0 && n <= 2*m && m <= 2*n) ? "YES\n" : "NO\n");
    }
}