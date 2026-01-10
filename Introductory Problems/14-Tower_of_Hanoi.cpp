// https://cses.fi/paste/69f0ab8e3d600263f20c96/
/* 
    This is a recursion based problem , in which we need to minimise the steps
    so lets imagine backwards what should happen 
    lets name three towers as start, auxiliary(helper) and the end

    # we need to move n discs from A to C using help of auxiliary (B)
    Imagine the last state when we put the biggest disc in final tower
    so there will be all n-1 disc in auxiliary tower , one disc in start , 
    now we will move that one biggest disc from start to end

            A       B       C
    ->      N       0       0
    ->      1       N-1     0
    ->      0       N-1     1
    now what is the subproblem ?
    # we need to put the n-1 disc from B to C using A as helper

    so we can derive the total number of moves from similar to fibonaaci series derivation
    here also, we calling T(n) = 2T(n-1) + 1

    therefore in total total = 2^n - 1

    TC - O(2^n)
    SC - O(n) recursion stack

*/
#include<bits/stdc++.h>
using namespace std;

void hanoi(int numDisc, int start, int end, int helper) {
    if(numDisc == 1) {
        cout << start << " " << end << "\n";
        return ;
    }

    hanoi(numDisc-1, start, helper, end);
    cout << start << " " << end << "\n";
    hanoi(numDisc-1, helper, end, start);
}

int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    hanoi(n, 1, 3, 2);
}