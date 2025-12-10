// https://cses.fi/paste/60c8323ca67b009ded4e7d/
/*
    We can have a doubly linkedlist storing the previous and next person to every person
    and then normally iterate
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>next(n+1, 0), prev(n+1, 0);
    next[n] = 1;
    for(int i = 1; i < n; i++) next[i] = i + 1;
    prev[1] = n;
    for(int i = 2; i <= n; i++) prev[i] = i - 1;

    int curr = 2;
    if(n == 1) {
        cout << 1 ;
        return 0;
    }

    while(next[curr] != prev[curr]) {
        cout << curr << " ";
        next[prev[curr]] = next[curr];
        prev[next[curr]] = prev[curr];

        curr = next[next[curr]];
    }
    
    cout << curr << " " << next[curr] ;
}


/*
    CSES Official Solution
    We create a vector that initially consists of numbers 1,2,...,n.
    After that we go through the vector and simulate the problem.
    We add every second number at the end of the vector and print every second number.
    We will process a total of n + n/2 + n/4 + ... = O(n) numbers, so the algorithm works in O(n) time.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0) {
            v.push_back(v[i]);
        } else {
            cout << v[i] << " ";
        }
    }
    cout << "\n";
}