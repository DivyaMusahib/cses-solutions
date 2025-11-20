// https://cses.fi/paste/f5e24741e727b76bea5232/
/*
    It doesn't matter what does the string consist we can find maximum length substring containing only one type of character by iterating
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 1, cnt = 1, n = s.size();
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout << ans;
}