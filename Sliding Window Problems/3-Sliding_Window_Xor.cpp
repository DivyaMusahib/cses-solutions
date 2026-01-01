// https://cses.fi/paste/885416d02c33f565f00c29/
/*
    use sliding window approach + xor property (a ^ a = 0 , 0 ^ x = x)
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<int>arr;
    arr.push_back(x);
    for(int i=1; i<n; i++) {
        int num = (1LL * a * arr.back() + b) % c;
        arr.push_back(num);
    }
    
    long long currXor = 0;
    for(int i=0; i<k; i++) {
        currXor ^= arr[i];
    }

    int i = 0; 
    long long ans = 0;
    for(int j=k; j<n; j++) {
        ans ^= currXor;
        currXor ^= arr[i++];
        currXor ^= arr[j];
    }
    ans ^= currXor;
    cout << ans;
}