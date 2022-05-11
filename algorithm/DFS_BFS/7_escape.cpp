// https://codeforces.com/group/gug2VsagsO/contest/381389/problem/D

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int m, n, A[N][N];
bool visited[N][N];

void input() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
}

struct Node {
    int i, j;

    Node(int _i, int _j) {
        i = _i;
        j = _j;
    }
};

void solve() {
    queue<Node> Q;
    Q.push(Node(1, 1));
    visited[1][1] = true;
    while (!Q.empty()) {
        Node node = Q.front();
        Q.pop();
        int i = node.i, j = node.j;
        if (i == m && j == n) {
            cout << "yes";
            return;
        }

        for (int a = 1; a <= min(A[i][j], m) ; ++a) {
            if (A[i][j] % a == 0) {
                int b = A[i][j] / a;
                if (!visited[a][b]) {
                    Q.push(Node(a, b));
                    visited[a][b] = true;
                }
            }
        }
    }
    cout << "no";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    return 0;
}