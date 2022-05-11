// https://codeforces.com/group/gug2VsagsO/contest/381388/problem/A

#include <bits/stdc++.h>

using namespace std;

const long long N = 1000;
long long f, s, g, u, d;
bool mark[N][N];

struct Node {
    int oldF, newF, step;

    Node(int x, int y, int _step) {
        oldF = x;
        newF = y;
        step = _step;
    }
};

int solve() {
    queue<Node> Q;
    Q.push(Node(s, s, 0));
    mark[s][s] = true;

    while (!Q.empty()) {
        Node node = Q.front();
        Q.pop();
        int newF = node.oldF + u;

        if (node.oldF + u == g)
            return node.step + 1;

        if (newF <= f && newF >= 1 && !mark[node.oldF][newF]) {
            Q.push(Node(newF, newF, node.step + 1));
            mark[node.oldF][newF] = true;
            node.oldF = newF;
        }

        newF = node.oldF - d;
        if (newF == g)
            return node.step + 1;

        if (newF >= 1 && newF <= f && !mark[node.oldF][newF]) {
            Q.push(Node(newF, newF, node.step + 1));
            mark[node.oldF][newF] = true;
            node.oldF = newF;
        }
    }

    return -1;
}

int main() {
    cin >> f >> s >> g >> u >> d;
    if (solve() < 0)
        cout << "use the stairs";
    else
        cout << solve();
    return 0;
}