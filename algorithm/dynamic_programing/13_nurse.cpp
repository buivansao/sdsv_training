// https://codeforces.com/group/gug2VsagsO/contest/381387/problem/N

#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5;
int n, k1, k2;
int S0[N], S1[N];

int main() {
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; i++) {
        S0[i] = 0;
        S1[i] = 0;
    }
    S0[1] = 1;
    S1[k1] = 1;
    S0[0] = 1;
    for (int i = k1 + 1; i <= n; i++) {
        S0[i] = S1[i - 1];
        int start = max(0, i - k2);
        for (int j = start; j <= i - k1; j++)
            S1[i] += S0[j];
    }
    int ans = S0[n] + S1[n];
    cout << ans;
    return 0;
}
