// https://codeforces.com/group/gug2VsagsO/contest/381387/problem/L

#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int n;
int a[N];
int SC[N], SL[N];
bool BC[N];
bool BL[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if (a[1] % 2 == 0) {
        SC[1] = a[1];
        BC[1] = true;
        BL[1] = false;
    } else {
        BC[1] = false;
        SL[1] = a[1];
        BL[1] = true;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] % 2 == 0) { // a[i] chan
            if (BC[i - 1] && SC[i - 1] > 0) {
                SC[i] = SC[i - 1] + a[i];
                BC[i] = true;
            } else {
                SC[i] = a[i];
                BC[i] = true;
            }
            if (BL[i - 1]) {
                SL[i] = SL[i - 1] + a[i];
                BL[i] = true;
            } else {
                BL[i] = false;
            }
        } else {// a[i] le
            if (BL[i - 1]) {
                SC[i] = SL[i - 1] + a[i];
                BC[i] = true;
            } else {
                BC[i] = false;
            }
            if (BC[i - 1] && SC[i - 1] > 0) {
                SL[i] = SC[i - 1] + a[i];
                BL[i] = true;
            } else {
                SL[i] = a[i];
                BL[i] = true;
            }
        }

    }
    bool found = false;
    int ans = -1e9;
    for (int i = 1; i <= n; i++) {
        if (BC[i] && SC[i] > ans) {
            ans = SC[i];
            found = true;
        }
    }
    if (found) {
        cout << ans;
    } else {
        cout << "NOT_FOUND";
    }
    return 0;
}

