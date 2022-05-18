#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int a[N], b[N];

int main() {
    int n, count = 0;
    queue<int> q;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        q.push(a[i]);
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n ; ++i) {
        while (q.front() != b[i]) {
            int x = q.front();
            q.pop();
            q.push(x);
            count++;
        }
        count++;
        q.pop();
    }

    cout << count;
}
