// https://cses.fi/paste/dfd42b975f68008eeb5a47/
/*
    This is a sweep line algorithm based question
    what we do is sort the entry and exit time of customers and 
    keep a counter of curr customers inside
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int,int>>arr;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    int curr = 0;
    for(int i=0; i<2*n; i++) {
        if(arr[i].second == 1) curr++;
        else curr--;
        ans = max(ans, curr);
    }
    cout << ans ;
}