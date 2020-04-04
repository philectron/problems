#include <bits/stdc++.h>

using namespace std;

void Solve(string s) {
    string sp;
    for (int i = 0, l = s.length(); i < l;) {
        if (s[i] == '1') {
            sp += '(';
            int j = i;
            while (j < l && s[j] == '1') {
                sp += s[j++];
            }
            i = j;
            sp += ')';
        } else {
            sp += s[i];
            i++;
        }
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
