// https://codeforces.com/group/gug2VsagsO/contest/381389/problem/K

#include <bits/stdc++.h>

#define N 10005

using namespace std;

int n, root;
int u, v;
vector<int> E[N];
int d[N];
int Cha[N];
bool mark[N];
int x, y;

void input() {
    cin >> n >> root;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    cin >> x >> y;
}

void BFS() {
    queue<int> Q;
    Q.push(root);
    mark[root] = true;
    d[root] = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v: E[u]) {
            if (mark[v] == false) {
                d[v] = d[u] + 1;
                Cha[v] = u;
                mark[v] = true;
                Q.push(v);
            }
        }
    }
}

void solve() {
    if (d[x] > d[y]) swap(x, y);
    while (d[y] > d[x]) y = Cha[y];
    while (x != y) {
        x = Cha[x];
        y = Cha[y];
    }
    cout << x;
}

int main() {
    input();
    BFS();
    solve();
    return 0;
}
