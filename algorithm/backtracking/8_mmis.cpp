// https://codeforces.com/group/gug2VsagsO/contest/381386/problem/G

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