// https://codeforces.com/group/gug2VsagsO/contest/381387/problem/A

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
int n;
long long A[N], B[N], F[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> A[i] >> B[i];

    F[n] = A[n];
    F[n - 1] = min(A[n - 1] + A[n], B[n - 1]);

    for (int i = n - 2; i >= 1; --i)
        F[i] = min(A[i] + F[i + 1], B[i] + F[i + 2]);

    cout << F[1];
    return 0;
}