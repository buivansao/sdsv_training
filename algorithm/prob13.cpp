/*
 * Cho đồ thị vô hướng G=(V,E). Tập M⊆V được gọi là tập độc lập nếu mọi cặp đỉnh trong M đều không kề nhau, tức là ∄x,y∈M sao cho (x,y)∈E. Một tập độc lập M được gọi là tối đại (maximal) nếu không tồn tại tập độc lập nào khác bao chứa M, tức là không thể bổ sung thêm đỉnh nào vào M mà vẫn giữ được tính chất một tập độc lập.

Trong số các tập độc lập tối đại của G, hãy tìm tập có lực lượng nhỏ nhất. Nói cách khác, cần tìm tập độc lập tối đại cực tiểu (minimum maximal independent set) của G
Input
Dòng đầu chứa số đỉnh và số cạnh của G: n m (1≤n≤20, 0≤m≤n×(n−1)/2)
m dòng tiếp theo, mỗi dòng chứa một cạnh của G: u v
Output
Gồm một số nguyên dương duy nhất là lực lượng của tập độc lập tối đại cực tiểu của G
Example
input
5 4
1 4
1 3
2 3
3 5
output
2
Note
Các tập độc lập tối đại của G trong ví dụ là: {1, 2, 5}, {2, 4, 5}, {3, 4}
 */

#include <bits/stdc++.h>

using namespace std;

//int m, n, ans = 1e9; // m la dinh, n la canh
//int a[100], c[100][100];
//
//
//void input() {
//    cin >> n;
//    int e;
//    cin >> e;
//    for (int i = 1; i <= e; i++) {
//        int x, y;
//        cin >> x >> y;
//        c[x][y] = c[y][x] = 1;
//    }
//}
//
//bool check(int i, int j) {
//    return a[i - 1] < j;
//}
//
//bool independent() {
//    for (int i = 1; i <= m; i++) {
//        for (int j = 1; j < i; j++) {
//            if (c[a[i]][a[j]]) return false;
//        }
//    }
//    return true;
//}
//
//bool maximal() {
//    return m == 2;
//}
//
//void solution() {
//    if (!independent()) return;
//    if (!maximal()) return;
//    if (m < ans) ans = m;
//}
//
//void Try(int i) {
//    for (int j = 1; j <= n; j++) {
//        if (check(i, j)) {
//            m++;
//            a[m] = j;
//            solution();
//            if (j < n) Try(i + 1);
//            m--;
//        }
//    }
//}
//
//int main() {
//    input();
//    Try(1);
//    cout << ans;
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

int n, m;
bool f[25][25];
int binary[25];
int ans = 1e9;

bool kiem_tra_doc_lap(set<int> S) {
    for (int i: S) {
        for (int j: S) {
            if (f[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

bool kiem_tra_doc_lap_cuc_dai(set<int> S) {
    for (int i = 1; i <= m; i++) {
        if (!S.count(i)) {
            S.insert(i);
            if (kiem_tra_doc_lap(S)) {
                return false;
            }
            S.erase(i);
        }
    }
    return true;
}

void tinh_kq() {
    set<int> S;
    for (int i = 1; i <= m; i++) {
        if (binary[i] == 1) {
            S.insert(i);
        }
    }
    if (kiem_tra_doc_lap(S)) {
        if (kiem_tra_doc_lap_cuc_dai(S)) {
            ans = min(ans, (int) S.size());
        }
    }
}

void Try(int k) {
    if (k > m) {
        tinh_kq();
    } else {
        for (int i = 0; i <= 1; i++) {
            binary[k] = i;
            Try(k + 1);
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        f[x][y] = f[y][x] = 1;
    }
    Try(1);
    cout << ans;
}