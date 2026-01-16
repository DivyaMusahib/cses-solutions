// https://cses.fi/paste/2b63fa72f9c3d332f36918/
/*
    lets observe the output for n = 5
    
    0 1 2 3 4
    1 0 3 2 5
    2 3 0 1 6
    3 2 1 0 7
    4 5 6 7 0

    We can see that for i = 0 the values are column number
    for the first column j = 0, the values are row number
    similarly when row and column number are same the answer will be 0

    -> (0, j) = j
    -> (i, 0) = i
    -> (i , i) = 0

    here we can observe that it is something like xor
    so lets verify for other places also
    for eg: 
        take i = 2, j = 4 
        grid[2][4] = 6
    so it is getting correct


    What is the proof that it is always correct ?

    ----
        so lets understand what we are doing,
        we are calulating mex of some pos[i, j]
        which is mex of all the rows above i that is [0...i-1,  j] and 
        all the columns before j that is [i, 0.....j-1]

        proof 
            we know according to our observation grid[i][j] = i ^ j
            lets assume there is some column k for which i ^ k =  i ^ j
            and (k < j)

            => i ^ k = i ^ j
                taking xor i both side
            => i ^ k ^ i = i ^ j ^ i
            => k = j (contradiction)

            we assumed column 'k' before column 'j' but to have equality it should we be the same column

            result ,
                it means for some [i, j], i^j is not present in any col before j  [i, 0.....j-1]
                similarly , i ^ j is not present in any element i any row above i [0.....i-1, j]
            
                so it means, i^j is unique above rows and before columns
                
                now how can we proove its the smallest (no proof) just observation
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (i ^ j) << " ";
        }
        cout << "\n";
    }
}