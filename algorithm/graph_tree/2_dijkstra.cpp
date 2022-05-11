// https://codeforces.com/group/gug2VsagsO/contest/381390/problem/B

#include<bits/stdc++.h>

using namespace std;

const int N = 100001;
const int INF = 1e9;
int n, m;
int s, t;
int d[N];
vector<int> A[N];
vector<int> cost[N];
set<int> NonFixed;

struct Element {
    int priority;
    int u;

    Element() : priority(0), u(0) {}

    Element(int priority, int u) : priority(priority), u(u) {}

    bool operator<(const Element other) const {
        return priority > other.priority;
    }
};

priority_queue<Element> Q;

void input() {
    scanf("%d%d", &n, &m);
    for (int k = 1; k <= m; k++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        A[u].push_back(v);
        cost[u].push_back(w);
    }
    scanf("%d%d", &s, &t);
}

int selectMin() {
    int u = Q.top().u;
    Q.pop();
    return u;
}

void solve() {
    for (int v = 1; v <= n; v++) {
        d[v] = 1e9;
    }
    d[s] = 0;
    Q.push(Element(0, s));

    while (!Q.empty()) {
        int u = selectMin();
        if (u == t) break;
        for (int i = 0; i < A[u].size(); i++) {
            int v = A[u][i];
            int w = cost[u][i];
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(Element(d[v], v));
            }
        }
    }

    cout << d[t] << endl;

}

int main() {
    input();
    solve();
    return 0;
}
