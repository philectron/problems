#include <bits/stdc++.h>

using namespace std;

string OpenParen(int n) {
    string s(n, '(');
    return s;
}

string CloseParen(int n) {
    string s(n, ')');
    return s;
}

void Solve(string s) {
    string sp;
    int prevOpen = 0;
    for (int i = 0, l = s.length(); i < l; i++) {
        int si = s[i] - '0';
        if (si > prevOpen) {
            sp += OpenParen(si - prevOpen);
            sp += s[i];
            prevOpen = si;
        } else if (si == prevOpen) {
            sp += s[i];
        } else {
            sp += CloseParen(prevOpen - si);
            sp += s[i];
            prevOpen = si;
        }
    }

    if (prevOpen > 0) {
        sp += CloseParen(prevOpen);
    }

    cout << sp << endl;
}

int main() {
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++) {
        string s;
        cin >> s;

        cout << "Case #" << x << ": ";
        Solve(s);
    }

    return 0;
}
