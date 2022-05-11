/*
 * A Maze is represented by a 0-1 matrix aN×M in which ai,j = 1 means cell (i,j) is an obstacle, ai,j = 0 means cell (i,j) is free. From a free cell, we can go up, down, left, or right to an adjacent free cell. Compute the minimal number of steps to escape from a Maze from a given cell (i0,j0) within the Maze.

Input
Line 1 contains N,M,i0,j0 (2≤N,M≤900)
Line i+1 (i=1,…,N) contains the ith line of the matrix aN×M
Output
Unique line contains the number minimal of steps to escape the Maze or -1 if no way to escape the Maze.

Example
input
8 12 5 6
1 1 0 0 0 0 1 0 0 0 0 1
1 0 0 0 1 1 0 1 0 0 1 1
0 0 1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 0 1 0 1
1 0 0 1 0 0 0 0 0 1 0 0
1 0 1 0 1 0 0 0 1 0 1 0
0 0 0 0 1 0 1 0 0 0 0 0
1 0 1 1 0 1 1 1 0 1 0 1
output
7
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 905;
int n, m, start_row, start_col, C[N][N], visited[N][N];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

struct State {
    int row, col, step;

    State(int _row, int _col, int _step) {
        row = _row;
        col = _col;
        step = _step;
    }
};

void input() {
    cin >> n >> m >> start_row >> start_col;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> C[i][j];
        }
    }
}

int solve() {
    queue<State> Q;
    Q.push(State(start_row, start_col, 0));
    visited[start_row][start_col] = true;
    while (!Q.empty()) {
        State cur_state = Q.front();
        Q.pop();
        for (int k = 0; k < 4 ; ++k) {
            int new_row = cur_state.row + dr[k];
            int new_col = cur_state.col + dc[k];
            if (new_row < 1 || new_row > n || new_col < 1 || new_col > m)
                return cur_state.step + 1;
            if (C[new_row][new_col] == 0 && !visited[new_row][new_col]) {
                Q.push(State(new_row, new_col, cur_state.step + 1));
                visited[new_row][new_col] = true;
            }
        }
    }
}

int main() {
    input();
    cout << solve();
    return 0;
}