/*
 * Cho hai số nguyên dương n,k (1≤k≤n≤9). Hãy liệt kê tất cả các hoán vị của dãy (1,2,…,n) thỏa mãn hai số cạnh nhau trong hoán vị thì chênh lệch nhau không quá k đơn vị

Input
Gồm hai số nguyên dương n và k trên một dòng

Output
Ghi ra nhiều dòng, mỗi dòng có n số là một hoán vị tìm được. Các hoán vị cần được liệt kê theo thứ tự từ điển

Example
input
5 2
output
1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 3 2 4 5
1 3 5 4 2
2 1 3 4 5
2 1 3 5 4
2 4 5 3 1
3 1 2 4 5
3 5 4 2 1
4 2 1 3 5
4 5 3 1 2
4 5 3 2 1
5 3 1 2 4
5 3 4 2 1
5 4 2 1 3
5 4 2 3 1
5 4 3 1 2
5 4 3 2 1
 */

#include <bits/stdc++.h>

using namespace std;

int n, k, a[100];
bool mark[100];

bool check(int i, int j) {
    if (mark[j]) return false;
    if (i == 1) return true;
    return abs(a[i - 1] - j) <= k;
}

void solution() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (check(i, j)) {
            a[i] = j;
            mark[j] = true;
            if (i == n) solution();
            else Try(i + 1);
            mark[j] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) mark[i] = false;
    Try(1);
    return 0;
}
