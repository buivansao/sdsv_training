/*
 * There are two jugs, a-litres jug and b-litres jug (a,b are positive integers). There is a pump with unlimited water. Given a positive integer c, how to get exactly c litres.

Example: with a=6, b=8, and c=4, we perform 4 operations below to get exactly 4 litres (a state is represented by (x,y) in which x and y are respectively the amount of water in the 6-litres jug and the 8-litres jug):

Fill the 6-litres jug, we get (6,0)
Pour the 6-litres jug to the 8-litres jug, we get (0,6)
Fill the 6-litres jug, we get (6,6)
Pour the 6-litres jug to the 8-litres jug, we get (4,8)
Input
Unique line contains positive integers a,b,c (1≤a,b,c≤900).

Output
Line contains the minimal number of steps to get c litres or -1 if no solution found.

Example
inputCopy
6 8 4
outputCopy
4
 */

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