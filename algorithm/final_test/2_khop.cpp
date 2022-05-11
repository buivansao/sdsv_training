// https://codeforces.com/group/gug2VsagsO/contest/383268/problem/A

#include <bits/stdc++.h>

using namespace std;

const int N = 10005, inf = N;
int n, m, low[N], num[N], pa[N];
vector<int> A[N];

void DFS(int u) {
    num[u] = ++num[0];
    low[u] = inf;
    for (auto v: A[u]) {
        if (v == pa[u])continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            pa[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }
}

int find_cau() {
    int cau = 0;
    for (int v = 1; v <= n; v++)
        cau += pa[v] > 0 && low[v] >= num[v];

    return cau;
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

int main() {
    input();

    for (int u = 1; u <= n; u++)
        if (!num[u]) DFS(u);

    printf("%d", find_cau());

    return 0;
}
