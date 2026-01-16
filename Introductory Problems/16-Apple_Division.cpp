// Method - 1 https://cses.fi/paste/b7197a462f89ea0693ace9/
// Method - 2 https://cses.fi/paste/7b94edc1488a1342f2f03a/
/*
    Here we can see that we need to explore all subsets so one of the method is using recursion
    also as the constraints are low , n <= 20 so that number of subsets are 2^n

    Method - 1 Iterative
    we can take a number x which is equal to 2^n , which is a n bit number
    we can iterate to each number from 0 to 2^n-1 whose all n bits is either on or off
    means we can take in one subset and other parity in other subset

    Method - 2 Recusrion (backtracking)
    Explore all possibilites
*/
#include<bits/stdc++.h>
using namespace std;

int n;
long long total = 0;
long long ans = LLONG_MAX;
vector<int>arr;

void subsetSum(int ind, long long curr) {
    if(ind == n) {
        ans = min(ans, llabs(total - 2*curr));
        return;
    }
    subsetSum(ind+1, curr + arr[ind]);
    subsetSum(ind+1, curr);
}

int main() {
    cin >> n;
    arr.resize(n);
    for(auto &i : arr) cin >> i;
    total = accumulate(arr.begin(), arr.end(), 0LL);
    subsetSum(0, 0);
    cout << ans;
}


// method - 1
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    long long ans = INT_MAX;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    int x = pow(2,n);
    for(int i=0; i<x; i++){
        long long gr1 = 0, gr2 = 0;
        for(int j=0; j<n; j++){
            if(i & (1 << j)){
                gr1 += arr[j];
            }
            else{
                gr2 += arr[j];
            }
        }
        ans = min(ans , abs(gr1-gr2));
    }
    cout << ans ;
}