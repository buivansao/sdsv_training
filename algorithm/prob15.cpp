#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int n, m, cnt, a[N], sa, sb;

int tong_con_lai(int k) {
    int t = 0;
    for (int j = k; j <= n; j++) t += a[j];
    return t;
}

void Try(int k) {
    if (k > n) {
        if (sa == sb) cnt++;
    } else {
        for (int i = 0; i <= 2; i++) {
            if (i == 1) sa += a[k];
            if (i == 2) sb += a[k];

            if (abs(sa - sb) <= tong_con_lai(i + 1)) Try(k + 1);

            if (i == 1) sa -= a[k];
            if (i == 2) sb -= a[k];
        }
    }
}

int main() {
    cin >> n >> m;
    sa += m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Try(1);
    cout << cnt;
}