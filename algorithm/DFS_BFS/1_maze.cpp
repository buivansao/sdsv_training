// https://codeforces.com/group/gug2VsagsO/contest/381389/problem/A

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