/*
    We can observe that here we have to explore all different possibilities
    so we can have the first thought is recursion
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> board(8);

bool isValid(int x, int y) {
    if(board[x][y] == '*') return false;

    int row = x, col = y;
    while(row >=0) if(board[row--][col] == 'Q') return false;
    
    row = x; col = y;
    while(row >=0 && col >= 0) if(board[row--][col--] == 'Q') return false;
    
    row = x; col = y;
    while(row >=0 && col < 8) if(board[row--][col++] == 'Q') return false;

    return true;
}

int numberOfWays(int row) {
    if(row == 8) return 1;
    int ans = 0;
    for(int col = 0; col < 8; col++) {
        if(isValid(row, col)) {
            board[row][col] = 'Q';
            ans += numberOfWays(row+1);
            board[row][col] = '.';
        }
    }
    return ans;
}

int main() {
    for(string & i : board) cin >> i;
    int ans = numberOfWays(0);
    cout << ans ;
}