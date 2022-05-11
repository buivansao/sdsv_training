// https://codeforces.com/group/gug2VsagsO/contest/381387/problem/G

#include <bits/stdc++.h>

using namespace std;
const int N = 605;
int W, H;
int dungDuoc[N][N];
int save[N][N];

int dienTichThua(int n, int m) {
    if (dungDuoc[n][m]) return save[n][m];
    if (n > W || m > H) {
        save[n][m] = 0;
        dungDuoc[n][m] = true;
        return 0;
    }
    int ans = 1e9;
    for (int x = 1; x < n; x++)
        ans = min(ans, dienTichThua(x, m) + dienTichThua(n - x, m));
    for (int y = 1; y < m; y++)
        ans = min(ans, dienTichThua(n, y) + dienTichThua(n, m - y));
    ans = min(ans, m * n);
    save[n][m] = ans;
    dungDuoc[n][m] = true;
    return ans;

}

int main() {
    cin >> W >> H;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        dungDuoc[x][y] = true;
    }
    cout << dienTichThua(W, H);
    return 0;
}
