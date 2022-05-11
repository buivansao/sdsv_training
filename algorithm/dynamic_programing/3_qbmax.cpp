// https://codeforces.com/group/gug2VsagsO/contest/381387/problem/B

#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int m, n, A[N][N], F[N][N];

void input() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];

    for (int i = 1; i <= n; ++i)
        F[0][i] = F[m + 1][i] = -1e9;
}

void solve() {
    for (int i = 1; i <= m; ++i)
        F[i][n] = A[i][n];

    for (int j = n - 1; j >= 1; --j)
        for (int i = 1; i <= m; i++)
            F[i][j] = A[i][j] + max(F[i][j + 1], max(F[i - 1][j + 1], F[i + 1][j + 1]));

    int res = -1e9;
    for (int i = 1; i <= m; ++i)
        res = max(res, F[i][1]);
    cout << res;
}

int main() {
    input();
    solve();
    return 0;
}