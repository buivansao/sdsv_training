// https://codeforces.com/group/gug2VsagsO/contest/381387/problem/F

#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
int n;
int F[N];

int main() {
    cin >> n;
    F[0] = F[1] = 1;
    for (int i = 2; i <= n; ++i) {
        F[i] = (F[i - 1] + F[i - 2]) % 1000000007;
    }
    cout << F[n];
    return 0;
}