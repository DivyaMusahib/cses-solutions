// https://cses.fi/paste/85d570cc7268071cea51d6/
/*
    We know that from 1 to n only 1 number is missing and we know the rest n-1 terms 
    so if we subtract the sum of n-1 terms from sum of all numbers from 1 to n we will get the missing number
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long total = (n * (n+1))/2, sum = 0;
    
    for(int i = 0; i < n-1; i++) {
        long long temp;
        cin >> temp;
        sum += temp;
    }

    cout << total - sum;
}