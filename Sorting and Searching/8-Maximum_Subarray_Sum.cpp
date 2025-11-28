// https://cses.fi/paste/8732f087a6525bf2eb657b/
/*
    It is a standard question of Kadane's ALgorithm
    The idea of Kadane's algorithm is to traverse over the array from left to right
    and for each element, find the maximum sum among all subarrays ending at that element.
    The result will be the maximum of all these values. 
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int>a(n);
    for(int &i : a) cin >> i;
    long long ans = -1e9;
    long long curr = 0;
    for(int i=0; i<n; i++) {
        curr = max(1LL*a[i], curr + a[i]);
        ans = max(ans, curr);
    }
    cout << ans << "\n";
}