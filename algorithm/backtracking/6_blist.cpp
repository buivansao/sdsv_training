// https://codeforces.com/group/gug2VsagsO/contest/381386/problem/E

#include <bits/stdc++.h>

using namespace std;

int n, k, a[100];

void solution() {
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool check(int i, int j) {
    return a[i - 1] < j;
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (check(i, j)) {
            a[i] = j;
            if (i == k) {
                solution();
            } else {
                Try(i + 1);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    Try(1);
    return 0;
}
