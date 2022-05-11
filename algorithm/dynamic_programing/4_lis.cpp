// https://codeforces.com/group/gug2VsagsO/contest/381387/problem/D

#include <bits/stdc++.h>

using namespace std;

int n, A[1002], mark[1002], save[1002];

int solve(int k) {
    if (mark[k]) {
        return save[k];
    }

    int res = 1;

    for (int i = k + 1; i <= n; ++i)
        if (A[i] > A[k])
            res = max(res, 1 + solve(i));

    mark[k] = true;
    save[k] = res;
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> A[i];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, solve(i));

    cout << ans;
    return 0;
}
