#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int a[N];

int main() {
    int n;
    map<int, int> m;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << m[a[i]] << "\n";
        m[a[i]]++;
    }
}
