// https://cses.fi/paste/3b002b095aa6a5b5eb05d6/
/*
    If need to make plaindrome , 
    in even length palindrome every char occurs even number of times
    in odd length plaindrome exactly one char comes odd times and other comes even number of times
    either we can use a map or normal frequency array to find the palindrome
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int>freq(26, 0);
    for(auto i : s) {
        freq[i-'A']++;
    }
    
    int cntOdd = 0;
    for(int i=0; i<26; i++) {
        if(freq[i]&1) cntOdd++;
    }

    if(cntOdd > 1) cout << "NO SOLUTION";
    else {
        string ans = "";
        string mid = "";
        for(int i=0; i<26; i++) {
            ans += string(freq[i]/2, 'A'+i);
            if(freq[i] & 1) mid += 'A' + i;
        }
        string rev = ans;
        reverse(rev.begin(), rev.end());
        ans += mid;
        ans += rev;
        cout << ans << "\n";                
    }
}