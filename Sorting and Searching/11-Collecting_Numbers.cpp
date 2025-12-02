// https://cses.fi/paste/2f3ad77446aea5b3ec0188/
/*
    when x+1 is at lesser index then x 
    means we need to restart the round again
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int,int>>a(n);
    int ind = 0;
    for(auto &[i, j] : a) {cin >> i; j = ind++;}
    sort(a.begin(), a.end());
    int ans = 1;
    int prev = -1;
    for(int i=0; i<n; i++) {
        if(a[i].second < prev) ans++;
        prev = a[i].second;
    }
    cout << ans;
}