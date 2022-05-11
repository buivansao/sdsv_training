// https://codeforces.com/group/gug2VsagsO/contest/381386/problem/M

#include <bits/stdc++.h>

using namespace std;

int X[100], Y[100], n, A[10][10];

void solution() {
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j) {
            cout << A[i][j] << " ";
            if (j == 9) cout << "\n";
        }

    exit(0);
}

bool check(int i, int j, int v) {
    for (int x = 1; x <= 9; x++) {
        if (A[i][x] == v) return false;
    }

    for (int x = 1; x <= 9; x++) {
        if (A[x][j] == v) return false;
    }

    int x, y;
    if (i >= 1 && i <= 3) x = 1;
    else if (i >= 4 && i <= 6) x = 4;
    else x = 7;

    if (j >= 1 && j <= 3) y = 1;
    else if (j >= 4 && j <= 6) y = 4;
    else y = 7;

    for (int _x = x; _x < x + 3; _x++) {
        for (int _y = y; _y < y + 3; _y++) {
            if (A[_x][_y] == v) return false;
        }
    }

    return true;
}

void duyet(int i) {
    for (int v = 1; v <= 9; ++v) {
        if (check(X[i], Y[i], v)) {
            A[X[i]][Y[i]] = v;
            if (i == n) solution();
            else (duyet(i + 1));
            A[X[i]][Y[i]] = 0;
        }
    }
}

int main() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; j++) {
            cin >> A[i][j];
            if (A[i][j] == 0) {
                n++;
                X[n] = i, Y[n] = j;
            }
        }
    }
    duyet(1);
    return 0;
}
