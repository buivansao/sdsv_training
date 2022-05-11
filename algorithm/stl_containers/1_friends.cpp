// https://codeforces.com/group/gug2VsagsO/contest/381369/problem/A

#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
vector<int> f[N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        f[x].push_back(y); // push y to vector f with index x
        f[y].push_back(x); // push x to vector f with index y
        // vector f has format: { {1, 2}, {2, 3}... }
    }

    for (int i = 1; i <= n; ++i) {
        sort(f[i].begin(), f[i].end());
        for (int v: f[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
}
