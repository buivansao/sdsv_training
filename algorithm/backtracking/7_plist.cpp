// https://codeforces.com/group/gug2VsagsO/contest/381386/problem/F

#include <bits/stdc++.h>

using namespace std;

int n, k, a[100];
bool mark[100];

bool check(int i, int j) {
    if (mark[j]) return false;
    if (i == 1) return true;
    return abs(a[i - 1] - j) <= k;
}

void solution() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (check(i, j)) {
            a[i] = j;
            mark[j] = true;
            if (i == n) solution();
            else Try(i + 1);
            mark[j] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) mark[i] = false;
    Try(1);
    return 0;
}
