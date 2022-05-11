#include <bits/stdc++.h>

using namespace std;

int n, M, A[1001];
long long save[1001][1001];
bool mark[1001][1001];

long long dem(int i, int S) {
    if (mark[i][S]) {
        return save[i][S];
    }

    if (i > n) {
        return 1;
    }

    long long ans = dem(i + 1, S);
    if (A[i] <= S)
        ans += dem(i + 1, S - A[i]);

    mark[i][S] = true;
    save[i][S] = ans;
    return ans;
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    cout << dem(1, M);
}
