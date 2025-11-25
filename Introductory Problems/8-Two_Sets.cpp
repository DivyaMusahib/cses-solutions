// https://cses.fi/paste/9447205fcdba9229eae7d2/
/*
    If the sum is odd obviously we can not divide into 2 sets 
    if even we can normally take numbers from 1 in increasing order as soon as at some number the sum of all numbers till now exceeds (n*(n+1))/4 you can stop and remove the number which caused problem that will be some number from 1 to till now
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ll n; cin >> n;
    ll sum = ((n * (n+1)))/2;
    if(sum%2 == 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    ll curr = 0;
    set<int>st;
    sum /= 2;
    for(ll i=1; i<=n; i++) {
        curr += i;
        if(curr <= sum) st.insert(i);
        else {
            int diff = curr - sum;
            st.insert(i);
            st.erase(diff);
            break;
        }
    }
    set<int>st2;
    for(int i=1; i<=n; i++) if(st.find(i) == st.end()) st2.insert(i);
    cout << st.size() << "\n";
    for(int i : st) cout << i << " ";
    cout << "\n";
    cout << st2.size() << "\n";
    for(int i : st2) cout << i << " ";
}