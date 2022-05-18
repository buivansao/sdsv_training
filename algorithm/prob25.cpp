/*
 * R2-D2 là một trò chơi giải đố ô chữ được thiết kế dành riêng cho ATM. Trong trò chơi ô chữ này các ô hoặc là các chứ số hoặc là dấu '.'. Trò chơi được thiết kế là một bảng kích thước n×m. Một số ô ngăn cách các từ được biểu diễn bởi dấu '.', tất cả phần còn lại là chữ số. Một từ được xác định bởi một phân đoạn của các ô cùng cột hoặc hàng, giới hạn ở cả hai bên bởi ô '.' hoặc bị chặn bởi giới hạn của bảng.

Mục tiêu của ATM là thay đổi các ô chữ số sao cho mỗi từ trong bảng trò chơi ô chữ là một từ Palindrom. Hơn nữa, tổng chênh lệch thay đổi của tất cả các ô bị thay đổi càng nhỏ càng tốt, chênh lệch thay đổi của ô (i,j) được tính bằng d=|xi,j−yi,j| với xi,j là chữ số của ô (i,j) trong bảng ban đầu và yi,j là chữ số của ô (i,j) trong bảng sau khi biến đổi. Hãy giúp ATM tìm một giải pháp cho bài toán này.

Input
Dòng đầu tiên chứa hai số nguyên n, m (1≤n,m≤1000)
n dòng tiếp theo mối dòng chứa m ký tự hoặc là chữ số hoặc là ký tự '.'
Output
Ghi ra n dòng mỗi dòng m ký tự là bảng sau khi biến đổi để tất cả các từ là Palindrom. Nếu có nhiều cách thì in ra một cách bất kỳ.
Examples
input
3 3
123
456
789
output
323
454
323
input
4 3
.2.
.05
.2.
10.
output
.1.
.22
.2.
11.
input
10 10
.538......
...4...4..
...459157.
5...6..6..
7.16304815
9...6..1..
5...8..2..
138631.351
2...3...7.
7.......4.
output
.535......
...4...3..
...531135.
5...3..1..
2.11800811
1...6..1..
5...8..3..
136631.343
2...3...7.
5.......4.

 */

#include<bits/stdc++.h>

using namespace std;

int const N = 1005;
int n, m;
string s[N];
bool visited[N][N];

struct Cell {
    int i, j;
};

vector<Cell> adj[N][N];
vector<Cell> L;

void build_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '.') {
                int k = j;
                while (k < m - 1 && s[i][k + 1] != '.') k++;
                for (int x = j, y = k; x < y; x++, y--) {
                    adj[i][x].push_back({i, y});
                    adj[i][y].push_back({i, x});
                }
                j = k;
            }
        }
    }
    
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (s[i][j] != '.') {
                int k = i;
                while (k < n - 1 && s[k + 1][j] != '.') k++;
                for (int x = i, y = k; x < y; x++, y--) {
                    adj[x][j].push_back({y, j});
                    adj[y][j].push_back({x, j});
                }
                i = k;
            }
        }
    }
}

void DFS(int i, int j) {
    L.push_back({i, j});
    visited[i][j] = true;

    for (int t = 0; t < adj[i][j].size(); t++)
        if (!visited[adj[i][j][t].i][adj[i][j][t].j])
            DFS(adj[i][j][t].i, adj[i][j][t].j);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    build_graph();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && s[i][j] != '.') {
                L.clear();
                DFS(i, j);
                char best_c;
                int best_cost = 1e9;
                for (char c = '0'; c <= '9'; c++) {
                    int cost = 0;
                    for (int t = 0; t < L.size(); t++)
                        cost += abs(s[L[t].i][L[t].j] - c);

                    if (cost < best_cost) {
                        best_cost = cost;
                        best_c = c;
                    }
                }
                for (int t = 0; t < L.size(); t++)
                    s[L[t].i][L[t].j] = best_c;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << s[i] << endl;
}
