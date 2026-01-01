// https://cses.fi/paste/3aa70c3dfc836b8ef00bc1/
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
    
    long long sum = 0;
    for(int i=0; i<k; i++) {
        sum += arr[i];
    }

    int i = 0; 
    long long ans = 0;
    for(int j=k; j<n; j++) {
        ans ^= sum;
        sum -= arr[i++];
        sum += arr[j];
    }
    ans ^= sum;
    cout << ans;
}