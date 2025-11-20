// https://cses.fi/paste/15d6fc6c33c4c6eecc53b9/
/*
    We can do this question by brute force 
    Reason  - when n is odd it is mutiplying it by 3 and adding 1
            - which means if n is odd it will be converted to even (odd * odd(3) = odd , odd+1 = even) 
            - if n is even it will be divided by 2 or after above step it will be divided by 2
            - so number will be definitely reduced to 1 in finite number of operations
*/
 
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    long long n; 
    cin >> n;  
    cout << n << " ";
    while(n != 1) {
        if((n % 2) == 1) {
            n = 3*n + 1;
        } else {
            n /= 2;
        }
        cout << n << " ";
    } 
}