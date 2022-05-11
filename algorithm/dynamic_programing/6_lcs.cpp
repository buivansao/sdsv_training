// https://codeforces.com/group/gug2VsagsO/contest/381387/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 1002;

int n, A[N], m, B[N], save[N][N];
bool mark[N][N];

int dp(int sa, int sb) {
    if (mark[sa][sb])
        return save[sa][sb];

    if (sa > n || sb > m) {
        save[sa][sb] = 0;
        mark[sa][sb] = true;
        return 0;
    }

    int ans = 0;
    if (A[sa] == B[sb])
        ans = 1 + dp(sa + 1, sb + 1);

    ans = max(ans, dp(sa + 1, sb)); // ko lay A[sa]
    ans = max(ans, dp(sa, sb + 1)); // ko lay B[sb]

    mark[sa][sb] = true;
    save[sa][sb] = ans;

    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> A[i];

    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> B[i];

    cout << dp(1, 1);
    return 0;
}
