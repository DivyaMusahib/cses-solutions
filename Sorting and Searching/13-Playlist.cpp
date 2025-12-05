// https://cses.fi/paste/65c96506f84536f6ebfe7d/
/*
    We can have a data structure like map or set and 2 pointers to determine
    as soon as a duplicate is added 
    we remove all the numbers before the 1st occurence of it and check the length

    or we can have a queue instead of 2 pointer through which it is easy to calculate size and 
    remove elements before 1st occurence
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int>q;
    map<int,int>mp;
    int ans = 1;
    for(int i = 0 ; i < n; i++) {
        int x; cin >> x;
        while(mp.find(x) != mp.end()) {
            int num = q.front();
            q.pop();
            mp.erase(num);
        }
        q.push(x);
        mp[x]++;
        ans = max(ans, (int)q.size());
    }
    cout << ans;
}