// https://cses.fi/paste/b990541bd7da92dfeaf3d7/
/*
    What i thought is that to have a zero at end we need 2 * 5 as a factor ,
    for a number we have atleast n/2 times 2 as a factor but we have limited number of 5's as factor
    to calculate number of 5's factor we know that after every 5 integer the interger is divisble by 5
        for eg: 5, 10 , 15, 20 etc...
    so for example if n is 33 then we have (5, 10, 15, 20, 25, 30) as factors of 5 so count is 6  ans += (33/5)
    no its not complete we can observe that for number 25 , one more fcator is added means ans += (33/25)
    similarly for 125, 625 etc .. we can check and that is the answer
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long num = 5;
    long long ans = 0;
    while(5 * num <= INT_MAX) {
        ans += (n / num);
        num *= 5;        
    }
    cout << ans << "\n";
}