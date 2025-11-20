// https://cses.fi/paste/46c84a864e1e1aaeea5259/
/*
    Here what we will do is that if the current element of the array is smaller then previous element we will make it just as big as previous one so that the next element dont get much problem 
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long>a(n);
    for(auto &i : a) {
        cin >> i;
    }
    
    long long prev = -1e3, ans = 0;
    for(auto &i : a) {
        if(i < prev) ans += prev - i;
        prev = max(prev , i);
    }
    cout << ans << "\n";
}