// https://codeforces.com/group/gug2VsagsO/contest/381389/problem/F

#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int a, b, c;
bool visited[N][N];

struct Node {
    int x, y, step;

    Node(int _x, int _y, int _step) {
        x = _x;
        y = _y;
        step = _step;
    }
};

bool check(int x, int y) {
    return !visited[x][y];
}

bool checkFinal(int x, int y) {
    return x == c || y == c;
}

int solve() {
    queue<Node> Q;
    Q.push(Node(0, 0, 0));
    visited[0][0] = true;
    while (!Q.empty()) {
        Node node = Q.front();
        Q.pop();
        // do nuoc tu coc 1 ra ngoai
        int newX = 0;
        int newY = node.y;
        if (checkFinal(newX, newY)) return node.step + 1;
        if (check(newX, newY)) {
            Q.push(Node(newX, newY, node.step + 1));
            visited[newX][newY] = true;
        }
        //do nuoc tu coc 2 ra ngoai
        newX = node.x;
        newY = 0;
        if (checkFinal(newX, newY)) return node.step + 1;
        if (check(newX, newY)) {
            Q.push(Node(newX, newY, node.step + 1));
            visited[newX][newY] = true;
        }
        // do nuoc tu coc 1 sang coc 2
        if (node.x + node.y > b) {
            newX = node.x + node.y - b;
            newY = b;
        } else {
            newX = 0;
            newY = node.x + node.y;
        }
        if (checkFinal(newX, newY)) return node.step + 1;
        if (check(newX, newY)) {
            Q.push(Node(newX, newY, node.step + 1));
            visited[newX][newY] = true;
        }
        //do nuoc tu coc 2 sang coc 1
        if (node.x + node.y > a) {
            newX = a;
            newY = node.x + node.y - a;
        } else {
            newX = node.x + node.y;
            newY = 0;
        }
        if (checkFinal(newX, newY)) return node.step + 1;
        if (check(newX, newY)) {
            Q.push(Node(newX, newY, node.step + 1));
            visited[newX][newY] = true;
        }
        //do nuoc vao day coc 1
        newX = a;
        newY = node.y;
        if (checkFinal(newX, newY)) return node.step + 1;
        if (check(newX, newY)) {
            Q.push(Node(newX, newY, node.step + 1));
            visited[newX][newY] = true;
        }
        // do nuoc vao day coc 2
        newX = node.x;
        newY = b;
        if (checkFinal(newX, newY)) return node.step + 1;
        if (check(newX, newY)) {
            Q.push(Node(newX, newY, node.step + 1));
            visited[newX][newY] = true;
        }
    }
    return -1;
}

int main() {
    cin >> a >> b >> c;
    cout << solve();
    return 0;
}