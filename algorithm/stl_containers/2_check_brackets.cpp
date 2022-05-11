// https://codeforces.com/group/gug2VsagsO/contest/381369/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    stack<char> st;

    for (char i : str) {
        if (i == '{' || i == '(' || i == '[') {
            st.push(i);
        } else {
            if (st.empty()) {
                cout << 0;
                return 0;
            }

            char lastChar = st.top();
            st.pop();

            if (i == ']' && lastChar != '[') {
                cout << 0;
                return 0;
            }

            if (i == '}' && lastChar != '{') {
                cout << 0;
                return 0;
            }

            if (i == ')' && lastChar != '(') {
                cout << 0;
                return 0;
            }
        }
    }

    (cout << st.empty()) ? 1 : 0;
}