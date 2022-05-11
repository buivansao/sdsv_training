// https://codeforces.com/group/gug2VsagsO/contest/381389/problem/E

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
