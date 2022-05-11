// https://codeforces.com/group/gug2VsagsO/contest/381386/problem/Q

#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int n, m, H[N], A[N][N];
int load[N]; // load[N]:tong thoi luong cac mon duoc phan cho giao vien i
int X[N]; // X[N]: giao vien duoc phan cong mon i
vector<int> T[N]; // danh sach giao vien co the day mon i
int minValue = 1e9, maxValue = -1e9;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> H[i];
    }

    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int t;
            cin >> t;
            T[i].push_back(t);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> A[i][j];
        }
    }
}

bool check(int k, int v) {
    for (int i = 1; i <= k - 1; ++i) {
        if (X[i] == v && A[i][k] == 1)
            return false;
    }
    return true;
}

void solution() {
    for (int i = 1; i <= m; ++i)
        maxValue = max(load[i], maxValue);
    if (minValue > maxValue)
        minValue = maxValue;
}

void Try(int k) {
    for (int i = 0; i < T[k].size(); ++i) {
        int v = T[k][i];
        if (check(k, v)) {
            X[k] = v;
            load[v] += H[k];
            if (k == n)
                solution();
            else
                Try(k + 1);
            load[v] -= H[k];
        }
    }
}

int main() {
    input();
    Try(1);
    cout << minValue;
    return 0;
}
