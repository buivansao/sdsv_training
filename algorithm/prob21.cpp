/*
* At the beginning of the semester, the head of a computer science department D have to assign courses to teachers in a balanced way. The department D has m teachers T={1,2,...,m} and n courses C={1,2,...,n}. Each course c∈C has a duration hc. Each teacher t∈T has a preference list which is a list of courses he/she can teach depending on his/her specialization. We know a list of pairs of conflicting two courses that cannot be assigned to the same teacher as these courses have been already scheduled in the same slot of the timetable. This conflict information is represented by a conflict matrix A in which A(i,j)=1 indicates that course i and j are conflict.The load of a teacher is the total duration of courses assigned to her/him. How to assign n courses to m teacher such that each course assigned to a teacher is in his/her preference list, no two conflicting courses are assigned to the same teacher, and the maximal load of teachers is minimal.

Input
Line 1 contains n and m (1≤n≤20,2≤m≤5)
Line 2 contains h1,…,hn
Line i+2 (i=1,...,n) contains a positive integer k followed by k positive integers which are the teachers who can teach course i.
Line i+n+2 (i=1,...,n) contains the ith line of the conflict matrix A
Output
The output contains a unique number which is the maximal load of the teachers in the solution found and the value -1 if not solution found.

Example
input
4 2
3 7 2 1
2 1 2
2 1 2
2 1 2
2 1 2
0 0 0 1
0 0 0 0
0 0 0 1
1 0 1 0
output
8
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int n, m, H[N], A[N][N];
int load[N]; // load[N]:tong thoi luong cac mon duoc phan cho giao vien i
int X[N]; // X[N]: giao vien duoc phan cong mon i
vector<int> T[N]; // danh sach giao vien co the day mon i
int minValue = 1e9, maxValue = -1e9;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> H[i];
    }

    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int t;
            cin >> t;
            T[i].push_back(t);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> A[i][j];
        }
    }
}

bool check(int k, int v) {
    for (int i = 1; i <= k - 1; ++i) {
        if (X[i] == v && A[i][k] == 1)
            return false;
    }
    return true;
}

void solution() {
    for (int i = 1; i <= m; ++i)
        maxValue = max(load[i], maxValue);
    if (minValue > maxValue)
        minValue = maxValue;
}

void Try(int k) {
    for (int i = 0; i < T[k].size(); ++i) {
        int v = T[k][i];
        if (check(k, v)) {
            X[k] = v;
            load[v] += H[k];
            if (k == n)
                solution();
            else
                Try(k + 1);
            load[v] -= H[k];
        }
    }
}

int main() {
    input();
    Try(1);
    cout << minValue;
    return 0;
}
