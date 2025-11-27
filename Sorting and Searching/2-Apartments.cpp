// https://cses.fi/paste/470950a1d3fa05b1eb3656/
/*
    We will sort both the desired size and the available size,
    now using a 2 pointer approach
    we can check for the current person desired size if the available size is +k or -k of the desired size 
    we will now check whether the available size can be used to some next person or not
    if it can't be used for future persons also we will drop it, else we move to the next person
*/
#include<bits/stdc++.h>
using namespace std;
#define all(arr) arr.begin(), arr.end()

int main() {
    int n, m , k;
    cin >> n >> m >> k;
    vector<int>desired(n), available(m);
    for(auto &i : desired) cin >> i;
    for(auto &i : available) cin >> i;
    
    int ans = 0;
    sort(all(desired));
    sort(all(available));
    int j = 0;
    for(int i = 0; i < n && j < m; i++) {
        if(abs(available[j] - desired[i]) <= k) {
            ans++;
            j++;
        } else if(available[j] < desired[i]) {
            j++;
            i--;
        }
    }
    cout << ans ;
}