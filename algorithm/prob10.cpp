#include <bits/stdc++.h>

using namespace std;

int n, m;
int x[20];
int a[20];
int Cm = 1e9;
int T = 0, dem = 0;

bool check(int v, int k) {
    if (k == n - 1) {
        return T + v * a[k] == m;
    }
    return true;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (Cm > a[i]) Cm = a[i];
    }
}

void Try(int k) {
    for (int v = 1; v <= m - T - (n - 1 - k) * Cm; v++) {
        if (check(v, k)) {
            x[k] = v;
            T = T + a[k] * v;
            if (k == n - 1) dem++;
            else Try(k + 1);
            T = T - a[k] * v;
        }
    }
}

int main() {
    input();
    Try(0);
    cout << dem;
    return 0;
}