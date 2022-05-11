#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int n, m, t = 0, x[N];

void solution() {
    for (int i = 1; i <= n; ++i) {
        cout << x[i] << " ";
    }
    cout << "\n";
}

bool check(int k, int v) {
    if (k == n) {
        return t + v == m;
    }
    return true;
}

void Try(int k) {
    for (int v = 1; v <= m; v++) {
        if (check(k, v)) {
            x[k] = v;
            t += x[k];
            if (k == n) {
                solution();
            } else {
                Try(k + 1);
            }
            t -= x[k];
        }
    }
}

int main() {
    cin >> n >> m;
    Try(1);
    return 0;
}