#include <bits/stdc++.h>

using namespace std;

#define MAX_QUERY 150

int main() {
    int t, b;
    cin >> t >> b;

    for (int x = 1; x <= t; x++) {
        string result;
        for (int p = 1; p <= b; p++) {
            if (p != 1 && p % 10 == 1) {

            } else {
                cout << p << endl;
                char c;
                cin >> c;
                if (c == 'N') return 1;

                result += c;
            }
        }
        cout << result << endl;
        char verdict;
        cin >> verdict;
        if (verdict == 'N') return 1;
    }

    return 0;
}
