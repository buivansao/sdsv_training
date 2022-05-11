/*
Cho hai số nguyên dương n,k (1≤k≤n≤20). Hãy liệt kê tất cả các tập con có k phần tử của {1,2,…,n}
Input
Gồm hai số nguyên dương n và k trên một dòng

Output
Ghi ra nhiều dòng, mỗi dòng có k số là các số trong một tập con tìm được.
Các phần tử của một tập con cần được in ra theo thứ tự tăng dần.
Các tập con cần được liệt kê theo thứ tự từ điển

Example
input
5 3
output
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
 */

#include <bits/stdc++.h>

using namespace std;

int n, k, a[100];

void solution() {
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool check(int i, int j) {
    return a[i - 1] < j;
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (check(i, j)) {
            a[i] = j;
            if (i == k) {
                solution();
            } else {
                Try(i + 1);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    Try(1);
    return 0;
}
