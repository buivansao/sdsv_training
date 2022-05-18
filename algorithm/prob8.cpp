#include <bits/stdc++.h>

using namespace std;

#define N 100

int n;
int x[N];
bool mark[N];

void solution() {
    for (int i = 1; i <= n; ++i) {
        cout << x[i] << " ";
    }
    cout << "\n";
}

bool check(int k, int v) {
    return !mark[v];
}

void Try(int k) {
    for (int v = 1; v <= n; v++) {
        if (check(k, v)) {
            x[k] = v;
            mark[v] = true;
            if (k == n) {
                solution();
            } else {
                Try(k + 1);
            }
            mark[v] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        mark[i] = false;
    }
    Try(1);
    return 0;
}