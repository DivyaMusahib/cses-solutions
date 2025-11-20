// https://cses.fi/paste/d2d99106081f569aea527c/
/*
    What i thought is that if difference of 1 is not allowed
        then how can i create the difference 2 ?
        It is easy to keep same parity numbers together and the largest and smallest of different parity together
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == 2 || n == 3) {
        cout << "NO SOLUTION";
    } else {
        for(int i = 2; i <= n; i += 2) 
            cout << i << " ";

        for(int i = 1; i <= n; i += 2)
            cout << i << " ";
    }
}