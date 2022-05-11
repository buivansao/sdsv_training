//https://codeforces.com/group/gug2VsagsO/contest/381386/problem/P

#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int n, k, cntPassengers, tmpF, fMin = 1e9, Cm = 1e9, C[N][N], X[N];
bool visited[N];

void input() {
    cin >> n >> k;

    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> C[i][j];
            if (i != j && Cm > C[i][j])
                Cm = C[i][j];
        }
    }
}

bool check(int i, int v) {
    if (visited[v])
        return false;
    if (v <= n) { // v la diem len xe
        if (visited[v + n] || cntPassengers >= k) // diem len xe da co
            return false;
    } else {
        if (!visited[v - n]) // diem don chua co
            return false;
    }
    return true;
}

void solution() {
    if (tmpF + C[X[2 * n]][X[0]] < fMin)
        fMin = tmpF + C[X[2 * n]][X[0]];
}

void Try(int i) {
    for (int v = 1; v <= 2 * n; v++) {
        if (check(i, v)) {
            X[i] = v;
            visited[v] = true;
            tmpF += C[X[i - 1]][X[i]];

            if (v <= n)
                cntPassengers += 1;
            else
                cntPassengers -= 1;

            if (i == 2 * n)
                solution();
            else if (tmpF + Cm * (2 * n + 1 - i) < fMin)
                Try(i + 1);

            visited[v] = false;
            tmpF -= C[X[i - 1]][X[i]];

            if (v <= n)
                cntPassengers -= 1;
            else
                cntPassengers += 1;
        }
    }
}

int main() {
    input();
    X[0] = 0;
    Try(1);
    cout << fMin;
    return 0;
}