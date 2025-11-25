// modular exponentiation
/*
    For every bit we have 2 choices that is on or off, total number of combinations is 2 ^ n
    To compute this efficiently, we use a well known algorithm called modular exponentiation.
    To achieve TC - O(log b) we divide the exponent and square the result (i.e., compute base ^ (power/2) and square it)
    Otherwise the time complexity would be O(b)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

ll modExp(ll a, ll b) {
    if(b == 0) return 1;
    ll curr = modExp(a, b/2);
    curr = (curr * curr) % mod;
    if(b&1) curr = (curr * a) % mod;
    return curr;
    
}

int main() {
    ll n;
    cin >> n;
    cout << modExp(2, n);
}

// https://cses.fi/paste/9776fe0407a24a2feaf4de/
// method 2 (no recursive stack space is getting used in this solution , it is iterative)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

ll modExp(ll base, ll exp) {
    ll ans = 1;
    base %= mod;
    // eg : to find = 5 ^ 13 
    //              13 = 1101 (Binary)
    //              5 ^ (8 + 4 + 1) 

    while(exp > 0) {
        // If current bit of exponent is 1, multiply result
        if(exp & 1) {
            ans = (ans * base) % mod; 
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    cout << modExp(2, n);
}
