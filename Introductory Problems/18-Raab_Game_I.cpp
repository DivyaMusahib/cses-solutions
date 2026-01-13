// https://cses.fi/paste/66046ecf5eb9ff99f2f165/
/*
    There is only 2 cases where answer can be No 
     1) a + b > n which is not possible as sum of wins should be <= number of game
     2) if one is zero which means at some point they will have same card which contradicts 
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if(a+b > n) {
            cout << "NO\n";
            continue;
        }

        int diff = a + b;
        if((a > 0 && b == 0) || (b > 0 && a == 0)) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for(int i = diff; i>(diff - a); i--) cout << i << " ";
        for(int i = 1; i <= (diff - a); i++) cout << i << " ";
        for(int i = (a+b+1); i <= n; i++) cout << i << " ";
        cout << "\n";
        
        for(int i = a; i >= 1; i--) cout << i << " ";
        for(int i = a+1; i <= diff; i++) cout << i << " ";
        for(int i = (a+b+1); i <= n; i++) cout << i << " ";
        cout << "\n";            
    }
}