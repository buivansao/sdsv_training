/*
 * Cho hai số a và b tìm bộ mã hóa sao cho khi mã hóa a ta được b. Ví dụ a=243,b=15387 bộ mã hóa tương ứng là 7 4 3 do b=27×102+44×10+33.

Input
Một dòng chứa hai số a và b (0≤a≤b<231).

Output
Ghi ra bộ mã hóa tìm được, dữ liệu đảm bảo tồn tại đúng một bộ mã hóa thỏa mãn.

Examples
input
2 2
output
1
input
243 15387
output
 */

#include <bits/stdc++.h>

using namespace std;

int a, b, X[20], P[20], F[20];
vector<int> A;
long long S = 0;

//long long mu(int k, int v) {
//    if (v == 0) return 1;
//    return mu(k, v - 1) * k;
//}

void input() {
    cin >> a >> b;
    while (a != 0) {
        int i = a % 10;
        A.push_back(i);
        a /= 10;
    }

    P[0] = 1;
    F[0] = 1;
    for (int i = 1; i <= 9; i++) {
        P[i] = P[i - 1] * 10;
        F[i] = F[i - 1] + P[i];
    }
}


void tinh_ket_qua() {
//    for (int i = 0; i <= A.size() - 1; i++) {
//        S += P[i] * pow(A[i], X[i]);
//    }
    if (S == b) {
        for (int i = A.size() - 1; i >= 0; --i) cout << X[i] << " ";
        exit(0);
    }
}

void Try(int k) {
    if (k < 0) {
        tinh_ket_qua();
    } else {
        long long mu = 1;
        for (int i = 0; i <= 31; i++) {
            X[k] = i;
            S += P[k] * mu;
            long long tmp = 0;
            if (k > 0) tmp = F[k - 1];
            if (S + tmp <= b) Try(k - 1);
            S -= P[k] * mu;
            mu *= A[k];
            if (S + mu > b) break;
        }
    }
}

int main() {
    input();
    Try(A.size() - 1);
    return 0;
}
