#include <bits/stdc++.h>

using namespace std;
const int N = 105;
int m, n;
int a[N][N];
int f[N][N];

int main() {
    //doc du lieu
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    //tinh cot thu n cua mang f
    for (int i = 1; i <= m; i++) {
        f[i][n] = a[i][n];
    }
    //dat bien cua f
    for (int j = 1; j <= n; j++) {
        f[0][j] = f[m + 1][j] = -1e9;
    }

    //tinh cac cot con lai
    for (int j = n - 1; j >= 1; j--) {
        for (int i = 1; i <= m; i++) {
            f[i][j] = max(a[i][j] + f[i - 1][j + 1], max(a[i][j] + f[i][j + 1], a[i][j] + f[i + 1][j + 1]));
        }
    }
    //tim max cot 1
    int ans = -1e9;
    for (int i = 1; i <= m; i++) ans = max(ans, f[i][1]);

    cout << ans << '\n';

    //truy vet
    //tim vtri batdau(i,j)
    int i = 1;
    int j = 1;
    for (int t = 1; t <= m; t++)
        if (f[t][1] > f[i][j]) i = t;
    //lap lai
    while (true) {
        cout << i << ' ';// in ra i
        if (j == n) break; // vtri ket thuc
        //tim vtri tiep theo
        int _i = i - 1, _j = j + 1;
        for (int t = i - 1; t <= i + 1; i++)
            if (f[t][j + 1] > f[_i][_j]) _i = t;
        //chuyen sang vtri tiep theo
        i = _i;
        j = _j;
    }
    return 0;
}
