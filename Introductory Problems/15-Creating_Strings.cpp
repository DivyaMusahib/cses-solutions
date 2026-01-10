// https://cses.fi/paste/cbc682ef38c9b2b2f23dcc/
/*
    One hint to this problem is that ,
    given we need all possibilities so we need to think of recursion
    We record the frquencies of all characters and make a string using them using recursion
*/
#include<bits/stdc++.h>
using namespace std;

vector<int>freq(26, 0);
vector<string>ans;

void func(string t) {
    int cnt = 0;
    for(auto i : freq) cnt += i;
    if(cnt == 0) {
        ans.push_back(t);
        return;
    }
    for(int i = 0; i < 26; i++) {
        if(freq[i] != 0) {
            t += ('a' + i);
            freq[i]--;
            func(t);
            t.pop_back();
            freq[i]++;
        }
    }
}

int main() {
    string s;
    cin >> s;
    for(auto i : s) {
        freq[i - 'a']++;
    }
    func("");
    cout << ans.size() << "\n";
    for(auto i : ans) cout << i << "\n";
}