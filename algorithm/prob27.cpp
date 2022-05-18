/*
 * A Knight is placed at a cell (r,c) (row r and column c) on a chess board n x n (rows and columns are numbered from 1, 2, ..., n). Can the Knight move to visit each cell of the chess board exactl once based on chess knight rules.

Input
Line 1: contains n (1 <= n <= 6)
Line 2: contains two positive integers r and c
Output
Write 1 if there is a solution for the knight and write 0, otherwise

Example
input
5
4 2
output
1
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 15;
int n, startRow, startCol;
bool visited[N][N];
int dr[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int dc[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int ans;

struct Node {
    Node() {}

    int row, col;

    Node(int _row, int _col) {
        row = _row;
        col = _col;
    }
};

Node X[N * N];

bool check(int row, int col) {
    return (row >= 1 && row <= n && col >= 1 && col <= n) && !visited[row][col];
}

void DFS(int k) {
    if (ans == 1)
        return;

    for (int i = 0; i < 8; ++i) {
        int newRow = X[k - 1].row + dr[i];
        int newCol = X[k - 1].col + dc[i];

        if (check(newRow, newCol)) {
            X[k] = Node(newRow, newCol);
            visited[newRow][newCol] = true;

            if (k == n * n)
                ans = 1;
            else
                DFS(k + 1);

            visited[newRow][newCol] = false;
        }
    }
}

int main() {
    cin >> n >> startRow >> startCol;
    X[1] = Node(startRow, startCol);
    visited[startRow][startCol] = true;
    DFS(2);
    cout << ans;
    return 0;
}
