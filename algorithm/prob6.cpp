#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int n;
int x[N];

void solution() {
    for (int i = 0; i < n; ++i) {
        cout << x[i];
    }
    cout << "\n";
}

bool check(int k, int v) {
    if (v == 1 && x[k - 1] == v) {
        return false;
    }
    return true;
}

void Try(int k) {
    for (int v = 0; v <= 1; ++v) {
        if (check(k, v)) {
            x[k] = v;
            if (k == n - 1) { // k from 0 -> n-1
                solution();
            } else {
                Try(k + 1);
            }
        }
    }
}

int main() {
    cin >> n;
    Try(0);
    return 0;
}