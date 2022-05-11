// https://codeforces.com/group/gug2VsagsO/contest/381389/problem/B

#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int n, m, A[N][N];
string M[N][N];
bool mark[N][N];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> M[i][j];
}

vector<string> cells(int i, int j) {
    vector<string> cells;
    string s = "";
    for (int k = 1; k < M[i][j].size(); ++k)
        if (M[i][j][k] == '+') {
            cells.push_back(s);
            s = "";
        } else
            s += M[i][j][k];


    cells.push_back(s);
    return cells;
}

int getCellIndex(string sj) {
    if (sj.size() == 1)
        return sj[0] - 'A' + 1;

    return (sj[0] - 'A' + 1) * 26 + (sj[1] - 'A' + 1);
}

void DFS(int i, int j) {
    if (!mark[i][j]) {
        mark[i][j] = true;

        if (M[i][j][0] != '=') {
            A[i][j] = stoi(M[i][j]);
        } else {
            A[i][j] = 0;

            vector<string> cell = cells(i, j);

            for (int k = 0; k < cell.size(); k++) {
                string s = cell[k];
                string si = "", sj = "";

                for (int t = 0; t < s.size(); ++t) {
                    if (isdigit(s[t]))
                        si += s[t];
                    else
                        sj += s[t];
                }

                int u = stoi(si);
                int v = getCellIndex(sj);

                DFS(u, v);
                A[i][j] += A[u][v];
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            DFS(i, j);
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    input();
    solve();
    return 0;
}