#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int n, f, f_min, c[N][N], x[N], Cm;
bool mark[N];

void solution() {
    if (f + c[x[n]][x[0]] < f_min) {
        f_min = f + c[x[n]][x[0]];
    }
}

void input() {
    cin >> n;
    Cm = 1e9;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if (i != j && Cm > c[i][j]) Cm = c[i][j];
        }
}

bool check(int v, int k) {
    return mark[v] == false;
}

void Try(int k) {
    for (int v = 1; v <= n; v++) {
        if (check(v, k)) {
            x[k] = v;
            mark[v] = true;
            f = f + c[x[k - 1]][x[k]];
            if (k == n) {
                solution();
            } else {
                if (f + Cm * (n + 1 - k) < f_min) {
                    Try(k + 1);
                }
            }
            mark[v] = false;
            f = f - c[x[k - 1]][x[k]];
        }
    }
}

void solve() {
    for (int v = 1; v <= n; v++) {
        mark[v] = false;
    }
    f = 0;
    f_min = 1e9;
    x[0] = 0;
    Try(1);
    cout << f_min;
}

int main() {
    input();
    solve();
    return 0;
}