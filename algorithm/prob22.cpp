/*
 * Given a undirected graph G=(V,E) where V={1,…,N} is the number of nodes and the set E has M edges. Compute number of connected components of G.

Input
Line 1: two positive integers N and M (1≤N≤105,1≤M≤105)
Lline i+1 (i=1,…,M): contains two positive integers u and v which are endpoints of ith edge
Output
Write the number of connected components of G.

Example
input
8 8
1 2
1 7
1 8
2 7
4 5
4 6
5 6
7 8
output
3
 */

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