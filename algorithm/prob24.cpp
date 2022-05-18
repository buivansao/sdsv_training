#include<bits/stdc++.h>

using namespace std;

const int N = 1005;
int n, cnt, A[N][N];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
}

int solve() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (A[i][j] == 1)
                cnt++;

    return cnt / 2;
}

int main() {
    input();
    cout << solve();
    return 0;
}