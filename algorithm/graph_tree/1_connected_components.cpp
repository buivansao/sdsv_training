// https://codeforces.com/group/gug2VsagsO/contest/381390/problem/A

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n, m, result, index[N];
vector<int> C[N];
bool mark[N];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        C[x].push_back(y);
        C[y].push_back(x);
    }
}

void DFS(int u) {
    mark[u] = true;
    index[u] = result;
    for (int i: C[u]) {
        if (!mark[i]) {
            DFS(i);
        }
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (!mark[i]) {
            index[i] = result++;
            DFS(i);
        }
    }

    cout << result << "\n";

    for (int i = 1; i <= result; ++i) {
        cout << "cc[" << i << "]: ";
        for (int j = 1; j <= n; ++j) {
            if (index[j] == i)
                cout << j << " ";
        }
        cout << "\n";
    }
}

int main() {
    input();
    solve();
    return 0;
}