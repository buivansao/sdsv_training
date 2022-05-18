#include <bits/stdc++.h>

using namespace std;

int A[10][10], B[10][10], n, cntA, cntB, _cntB, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

//void TryA(int x, int y, int h) {
//    int _x = x + dx[h];
//    int _y = y + dy[h];
//
//    if (A[_x][_y] == 0) {
//        cntA++;
//        A[x][y] = 2;
//        TryA(_x, _y, h);
//    } else if (A[_x][_y] == 1) {
//        TryA(x, y, (h + 3) % 4);
//    } else if (A[_x][_y] == 2) return;
//}

void solution() {
    if (_cntB > cntB) cntB = _cntB;
}

void TryB(int x, int y, int h, bool moved) {
    int _x = x + dx[h];
    int _y = y + dy[h];

    if (B[_x][_y] == 0) {
        _cntB++;
        B[x][y] = 2;
        TryB(_x, _y, h, true);
        B[x][y] = 0;
        _cntB--;
    } else if (B[_x][_y] == 1 && moved) {
        TryB(x, y, (h + 1) % 4, false);
        TryB(x, y, (h + 3) % 4, false);
    } else if (B[_x][_y] == 2) {
        solution();
        return;
    }
}
   n
int main() {
    cin >> n;

    // h: 0 - up, 1 - right, 2 - down, 3 - left
    // 1: chuong ngai vat, 0: trong, 2 la da di qua

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int y = s[0] - 'A' + 1;
        int x = s[1] - '0';
//        A[x][y] = 1;
        B[x][y] = 1;
    }

    // gan 4 vien la 1
    for (int i = 1; i <= 8; ++i) {
//        A[i][0] = A[0][i] = A[9][i] = A[i][9] = 1;
        B[i][0] = B[0][i] = B[9][i] = B[i][9] = 1;
    }

//    TryA(1, 1, 2);
    TryB(1, 1, 2, false);
//    cout << cntA;
    cout << cntB;
    return 0;
}