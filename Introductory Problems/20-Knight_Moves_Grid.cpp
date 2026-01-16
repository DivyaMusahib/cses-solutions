// https://cses.fi/paste/72e515d5b8704076f369c2/
/*
    simple bf algo
    TC O(n x n x 8)
    SC O(n x n)
*/
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>grid;

int xi[] = {1, 1, -1, -1, 2, 2, -2, -2};
int yi[] = {2, -2, 2, -2, 1, -1, 1, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == -1;
}

void bfs() {
    grid[0][0] = 0;
    queue<pair<int,int>>q;
    q.push({0, 0});
    while(!q.empty()) {
        auto [currX, currY] = q.front();
        q.pop();
        for(int i = 0; i < 8; i++) {
            int newX = currX + xi[i];
            int newY = currY + yi[i];

            if(isValid(newX, newY)) {
                grid[newX][newY] = grid[currX][currY] + 1;
                q.push({newX, newY});
            }
        }
    }
}

int main() {
    cin >> n;
    grid.assign(n, vector<int>(n, -1));
    bfs();

    for(auto i : grid) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}