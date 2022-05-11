/*
 * Viết chương trình xây dựng một bảng tính đơn giản. Bảng tính cần xây dựng được chia thành R hàng và S cột, các hàng được đánh số từ 1, các cột được đánh dầu bằng chuỗi ký tự như sau: A, B, C, ..., Z, AA, AB, AC, ... AZ, BA, BB, BC, ...Giao của hàng x và mỗi cột Y là ô Yx có thể nhận giá trị là một số, hoặc một hàm bắt đầu bằng dấu '=' sau đó là địa chỉ của các ô trong phép tính cách nhau bằng dấu '+' (chỉ chứa địa chỉ các ô chứ không chứa số, có tối đa 10 địa chỉ trong biểu thức)

Input
Dòng đầu chứa 2 số nguyên R và S (0<R,S≤100)

Từ dòng thứ 2 đến dòng R+1 mỗi dùng chứa thông tin của S ô là một số nguyên không âm không vượt quá 100 hoặc một biểu thức. Dữ liệu đảm bảo không có các biểu thức là chu trình

Output
Ghi ra R dòng mỗi dòng S số là kết quả của bảng tính tại từng ô lấy module cho 231
 Examples
input
3 4
10 34 37 =A1+B1+C1
40 17 34 =A2+B2+C2
=A1+A2 =B1+B2 =C1+C2 =D1+D2
output
10 34 37 81
40 17 34 91
50 51 71 172
input
5 4
11 =A5+A3+D5+C4+B2 2 =D4+C4+A1+B4
=B3+C4 5 =A2+D5 5
=B3 13 9 =C5+C3+C1+A1+B1
2 14 9 =B2+D5+C3
=C5+B5+D2+D2 =B3 3 =A4+A1+B2+B4
output
11 85 2 80
22 5 54 5
13 13 9 110
2 14 9 46
26 13 3 32

 */

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