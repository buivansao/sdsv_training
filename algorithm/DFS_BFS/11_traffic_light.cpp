// https://codeforces.com/group/gug2VsagsO/contest/381389/problem/L

#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> Dinhke[10004];
vector<int> kq;
bool mark[10004];

bool check(int i) {
    for (int v = 1; v <= n; v++) mark[v] = false;
    queue<int> Q;
    Q.push(Dinhke[i][0]);
    mark[Dinhke[i][0]] = true;
    while (!Q.empty()) {
        int s = Q.front();
        Q.pop();
        for (int v: Dinhke[s]) {
            if (!mark[v] && v != i) {
                Q.push(v);
                mark[v] = true;
            }
        }
    }
    for (int v: Dinhke[i])
        if (!mark[v])
            return true;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        Dinhke[x].push_back(y);
        Dinhke[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        if (Dinhke[i].size() != 0)
            if (check(i)) kq.push_back(i);
    cout << kq.size() << endl;
    for (int i: kq) cout << i << " ";
    return 0;
}
