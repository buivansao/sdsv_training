/*
 * There are n passengers 1,2,…,n. The passenger i want to travel from point i to point i+n(i=1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j(i,j=0,1,…,2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0 without visiting any point more than once (except for the point 0).

Input
Line 1 contains n and k(1≤n≤11,1≤k≤10). Line i+1(i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).

Output
Unique line contains the length of the shortest route.

Example
input
3 2
0 8 5 1 10 5 9
9 0 5 6 6 2 8
2 2 0 3 8 7 2
5 3 4 0 3 2 7
9 6 8 7 0 9 10
3 8 10 6 5 0 2
3 4 4 5 2 2 0
output
25
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int n, k, cntPassengers, tmpF, fMin = 1e9, Cm = 1e9, C[N][N], X[N];
bool visited[N];

void input() {
    cin >> n >> k;

    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> C[i][j];
            if (i != j && Cm > C[i][j])
                Cm = C[i][j];
        }
    }
}

bool check(int i, int v) {
    if (visited[v])
        return false;
    if (v <= n) { // v la diem len xe
        if (visited[v + n] || cntPassengers >= k) // diem len xe da co
            return false;
    } else {
        if (!visited[v - n]) // diem don chua co
            return false;
    }
    return true;
}

void solution() {
    if (tmpF + C[X[2 * n]][X[0]] < fMin)
        fMin = tmpF + C[X[2 * n]][X[0]];
}

void Try(int i) {
    for (int v = 1; v <= 2 * n; v++) {
        if (check(i, v)) {
            X[i] = v;
            visited[v] = true;
            tmpF += C[X[i - 1]][X[i]];

            if (v <= n)
                cntPassengers += 1;
            else
                cntPassengers -= 1;

            if (i == 2 * n)
                solution();
            else if (tmpF + Cm * (2 * n + 1 - i) < fMin)
                Try(i + 1);

            visited[v] = false;
            tmpF -= C[X[i - 1]][X[i]];

            if (v <= n)
                cntPassengers -= 1;
            else
                cntPassengers += 1;
        }
    }
}

int main() {
    input();
    X[0] = 0;
    Try(1);
    cout << fMin;
    return 0;
}