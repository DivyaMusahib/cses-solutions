// https://cses.fi/paste/0fb89bb27c46b3d2eb3da3/
/*
    We can thinl it as normal life scenario
    suppose a gondola has x kg capacity and we need all children to take a rid
    means heavy child will also take the ride ?
    so what we can do is that put a lighter child with the heavy child if some weight is left in the capacity
    with this strategy the space will be used better compare to putting lighter child together
    
    we will use 2 pointer apprach for this 
    choosing a light child with heavy child if possible , otherwise let heavy child go alone
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, capacity;
    cin >> n >> capacity;
    vector<ll>a(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    ll i = 0, j = n-1, ans = 0;
    while(i < j) {
        if(a[i] + a[j] <= capacity) {
            i++;
            j--;
            ans++;
        } else {
            j--;
            ans++;
        }
    }
    if(i == j) ans++;
    cout << ans ;
}