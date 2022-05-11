// https://codeforces.com/group/gug2VsagsO/contest/381387/problem/M

#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int n;
int a[N];
int S[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S[1] = a[1];
        S[i] = max(S[i - 1] + a[i], a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, S[i]);
    }
    cout << ans;
    return 0;
}
