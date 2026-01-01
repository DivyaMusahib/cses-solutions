// https://cses.fi/paste/1417795b9651d26df00cc4/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }    

    map<int,int>mp; // TC -> nlogk (allowed as n, k <= 1e5 ) 
    for(int i=0; i<k; i++) {
        mp[arr[i]]++;
    }

    int i = 0;
    for(int j=k; j<n; j++) {
        cout << mp.size() << " ";
        mp[arr[i]]--;
        if(mp[arr[i]] == 0) mp.erase(arr[i]);
        i++;
        mp[arr[j]]++;
    }
    cout << mp.size();
}