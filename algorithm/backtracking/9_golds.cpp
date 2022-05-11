// https://codeforces.com/group/gug2VsagsO/contest/381386/problem/H

#include <bits/stdc++.h>

using namespace std;

int n, m, cnt, s, a[45];

void Try(int k) {
    if (k > n) {
        cnt++;
    } else {
        for (int i = 0; i <= 1; i++) {
            s += (a[k] * i);
            if (s <= m) Try(k + 1);
            s -= (a[k] * i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Try(1);
    cout << cnt;
}
