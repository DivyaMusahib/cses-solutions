// https://cses.fi/paste/84187fe3977c8255eaf429/
/*
    total number of ways selecting any two places - number of place where they are in attacking position
    for every 2x3 box there were 2 position and also for every 3x2 box 2 position therefore
    #2x3 box = (k-1)*(k-2) -> 2 position
    #3x2 box = (k-1)*(k-2) -> 2 position
    => 4 * (k-1)*(k-2)
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n;
    cin >> n;
 
    for (long long i = 1 ; i <= n ; i++) {
        cout << (i * i) * (i * i - 1) / 2 - (4 * (i - 2) * (i - 1)) << "\n";
    }
 }