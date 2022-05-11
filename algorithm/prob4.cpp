#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int a[N];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<int> s; // push if not appear (unique element in array)
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (s.count(x) == 1) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
            s.insert(x);
        }
    }
}