// https://cses.fi/paste/b7d895b1561196b9ec0167/
/*
    We can see if we sort and check whether we can make 1 or not 2 or not but 
    how can we optimise it
    suppose we are at position 4 and total sum till now is 6 means i can make 1,2,3,4,5,6
    so if i add the number at position 4 to sum then we can make 1+a[i] to 6+a[i]
    what is 1+a[i] is 10 then it means we cant make 7 so 7 is the answer
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a(n); 
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        if((sum + 1) < a[i]) {
            break;
        }
        sum += a[i];
    }
    cout << sum + 1;
}