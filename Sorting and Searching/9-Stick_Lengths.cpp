// https://cses.fi/paste/f45e7d2d3e52e69deba3b6/
/*
    We will always move towards the median in this case
    
    reason suppose these are the numbers

          2 5 6 8 10 14 20 29 34 45 57
        a        b    c         d       e
          suppose we move all numbers to point 'b' it will obviously take more work then other 
          as many things overlaps draw it on pen and paper
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int>a(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    int mid = 0;
    if(n&1) mid = a[n/2];
    else mid = ((a[n/2] + a[(n-1)/2]) / 2);

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(mid - a[i]);
    }
    
    cout << ans;
}