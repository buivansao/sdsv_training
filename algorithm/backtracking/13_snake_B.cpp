// https://codeforces.com/group/gug2VsagsO/contest/381386/problem/L

#include <bits/stdc++.h>

using namespace std;

const int CO_VAT_CAN = 1;
const int DA_DI_QUA = 2;
const int TRONG = 0;
int A[10][10], n, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int do_dai_tot_nhat, do_dai_hien_tai;

int do_dai_co_the_di(int x, int y, int h) {
    int kq = 0;
    while (A[x + dx[h]][y + dy[h]] == TRONG) {
        kq++;
        x += dx[h];
        y += dy[h];
    }
    return kq;
}

void solution() {
    if (do_dai_tot_nhat > do_dai_hien_tai) do_dai_hien_tai = do_dai_tot_nhat;
}

void Try(int x, int y, int h) {
    int _x = x + dx[h], _y = y + dy[h];
    if (A[_x][_y] == DA_DI_QUA) {
        solution();
        return;
    }
    for (int _h: {(h + 3) % 4, (h + 1) % 4}) {
        int L = do_dai_co_the_di(x, y, _h);
        if (L != 0) {
            for (int i = 1; i <= L; i++) A[x + dx[_h] * i][y + dy[_h] * i] = DA_DI_QUA;

            do_dai_hien_tai += L;
            Try(x + dx[_h] * L, y + dy[_h] * L, _h);
            do_dai_hien_tai -= L;

            for (int i = 1; i <= L; ++i) A[x + dx[_h] * i][y + dy[_h] * i] = TRONG;
        }
    }
}

int main() {
    cin >> n;

    // h: 0 - up, 1 - right, 2 - down, 3 - left
    // 1: chuong ngai vat, 0: trong, 2 la da di qua

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int y = s[0] - 'A' + 1;
        int x = s[1] - '0';
        A[x][y] = CO_VAT_CAN;
    }
    for (int i = 1; i <= 8; ++i) A[i][0] = A[0][i] = A[9][i] = A[i][9] = CO_VAT_CAN;
    int L = do_dai_co_the_di(1, 1, 2);
    for (int i = 1; i <= L; i++) A[1 + dx[2] * i][1 + dy[2] * i] = DA_DI_QUA;
    do_dai_hien_tai = L;
    Try(1 + dx[2] * L, 1 + dy[2] * L, 2);
    cout << do_dai_tot_nhat;
    return 0;
}