// https://cses.fi/paste/4ea86fc8473c55e2ed077f/
/*
    We will do something like the previous task "playlist" in cses
    We can use a 2 pointer approach as soon as an elements repeats 
    we can count the number of subarrays from j to i-1 where i is the current index pointer
    now we will increase j till a[j] = a[i] occurs
    now new subarray from j to i is completely unique so we can move forward 
    but there is one overlapping that is current j to i-1 will be counted again later onwards
    so we will subtract number of subarrays from j to i-1
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &i : a) cin >> i;
    long long ans = 0;
    int j = 0;
    set<int>st;
    for(int i = 0; i < n; i++) {
        if(st.find(a[i]) != st.end()) {
            int len = i - j;
            ans += (1LL * (len) * (len +1)) / 2;
            while(a[j] != a[i]) {
                st.erase(a[j]);
                j++;
            }
            st.erase(a[j]);
            j++;
            int len2 = i - j;
            ans -= (1LL * (len2) * (len2 + 1)) / 2;
        }
        st.insert(a[i]);
    }
    int len = n - j ;
    ans += (1LL * (len) * (len + 1))  / 2;
    cout << ans ;
}   