// https://cses.fi/paste/f343d58ca01166c6eb3201/
/*
    It is very easy to count distinct elements , we can put all elements in the set 
    it will have nlogn TC 
    return size of set
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int>a(n);
    for(int &i : a) cin >> i;
    set<int>st(a.begin(), a.end());
    cout << st.size();
}

// Method - 2
// https://cses.fi/paste/6e3f1dbdc2c87779eb321d/
/*
    We can sort the array and check if adjacent elements are different then only we will increase the count
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int>a(n);
    for(int &i : a) cin >> i;
    sort(a.begin(), a.end());
    int ans = 1;
    for(int i=1; i<n; i++) {
        if(a[i] != a[i-1]) ans++;
    }
    cout << ans << "\n";
}