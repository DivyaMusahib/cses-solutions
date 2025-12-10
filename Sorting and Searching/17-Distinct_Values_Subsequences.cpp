// https://cses.fi/paste/3b35b878a44be8f5ed4c3a/
/*
    In a subsequence of unique integers either we will include an element or not,
    if some element is duplicate then we can decide which element to take 
    For eg : 4, 2, 2, 4, 3, 2, 4, 5, 7 

        elements 
            2 -> {}, {1}, {2}, {5} (either we will not choose 2 in our subsequence or choose one of the position)
            3 -> {}, {4}
            4 -> {}, {0}, {3}, {6}
            5 -> {}, {7}
            7 -> {}, {8}

            ans = 4c1 * 2c1 * 4c1 * 2c1 * 2c1 - 1 (case all not taken)
                = 4 * 2 * 4 * 2 * 2 - 1
                = multiplication of (freq+1) - 1 
*/
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    map<int,int>mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    
    int ans = 1;

    for(auto i : mp) {
        ans = (1LL * ans * (i.second + 1)) % mod;
    }

    cout << ans - 1;
}