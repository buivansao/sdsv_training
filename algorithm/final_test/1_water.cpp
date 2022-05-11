// https://codeforces.com/group/gug2VsagsO/contest/383268/problem/B

#include <bits/stdc++.h>

using namespace std;

const int N = 50;

int n, m, kq = 0, H[N][N], dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool visited[N][N];

struct State {
    int x, y;

    State() : x(0), y(y) {
    };

    State(int x, int y) : x(x), y(y) {
    };
};

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> H[i][j];
        }
    }
}

bool check(int sx, int sy, int k) {
    queue<State> Q;
    Q.push(State(sx, sy));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = false;
        }
    }
    visited[sx][sy] = true;
    while (!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        Q.pop();
        if (x == 1 || x == n || y == 1 || y == m) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (!visited[new_x][new_y] && H[new_x][new_y] < k) {
                Q.push(State(new_x, new_y));
                visited[new_x][new_y] = true;
            }
        }
    }
    return false;
}

void solve() {
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            for (int k = H[i][j] + 1; k <= 201; k++) {
                if (check(i, j, k)) {
                    kq += k - 1 - H[i][j];
                    break;
                }
            }
        }
    }
}

int main() {
    input();
    solve();
    cout << kq;
}
