// https://codeforces.com/group/gug2VsagsO/contest/381387/problem/I

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int n, a[N], mark[N], b[N], rs[N], max_index = -1, index = -1;


void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = 1;
    }
}

void solve() {
    for (int i = n; i > 0; i--) {
        for (int j = i + 1; j <= n; j++)
            if (a[j] > a[i]) b[i] = max(b[i], b[j] + 1);

        if (max_index < b[i]) {
            max_index = b[i];
            index = i;
        }
    }
}

int main() {
    input();
    solve();
    cout << max_index << "\n";
    int i = max_index;
    rs[max_index] = a[index];
    int j = index;

    while (i >= 1) {
        for (int t = j; t <= n; t++) {
            if (b[t] + 1 == i) {
                j = t;
                rs[i - 1] = a[t];
                break;
            }
        }
        i--;
    }
    for (int k = max_index; k > 0; k--)
        cout << rs[k] << " ";

    return 0;
}
