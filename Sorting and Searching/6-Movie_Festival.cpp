// https://cses.fi/paste/7f825176b20b037feb5bae/
/*
    It is a standard scheduling algorithm
    we can have 3 thinking out of which 1st 2 are wrong
        1. We can choose the shortest movie (Test case : {{1, 5}, {3, 7}, {6, 15}})
        2. Sort events on starting time and choose the earliest one  (Test case : {{1, 15}, {6, 10}, {12, 14}})
        
        correct choice
        3. Sort accordind to the events which are ending the earliest so that you can take as much as events
*/
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a, pair<int,int>b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>>arr(n);
    for(auto &[i, j] : arr) cin >> i >> j;
    sort(arr.begin(), arr.end(), cmp);
    int ans = 1;
    int lastEnded = arr[0].second;
    for(int i = 1; i < n; i++) {
        if(arr[i].first >= lastEnded) {
            ans ++;
            lastEnded = arr[i].second;
        }
    }
    cout << ans ;
}