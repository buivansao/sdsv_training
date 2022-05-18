/*
 * Trong chuyện cổ tích cây khế, con chim ăn khế và trả vàng cho người em. Chim chở người em đến chỗ chứa vàng, ở đó có n cục vàng. Cục thứ i có khối lượng là mi. Túi ba gang có sức chứa là M, hãy đếm xem có bao nhiêu cách để người em chọn các cục vàng để lấy. Hai cách lấy được coi là khác nhau nếu tồn tại i sao cho ở cách lấy này có lấy cục thứ i còn ở cách kia thì không

Input
Dòng đầu chứa: n M
Dòng tiếp theo chứa: m1 m2 … mn
Output
Một số nguyên duy nhất là số cách lấy vàng mà có tổng khối lượng không vượt quá sức chứa của túi

Scoring
n≤40, 1≤mi,M≤106
Có 50% với n≤20
Example
input
4 10
3 10 5 4
output
8
 */

#include <bits/stdc++.h>

using namespace std;

int n, m, cnt, s, a[45];

void Try(int k) {
    if (k > n) {
        cnt++;
    } else {
        for (int i = 0; i <= 1; i++) {
            s += (a[k] * i);
            if (s <= m) Try(k + 1);
            s -= (a[k] * i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Try(1);
    cout << cnt;
}
