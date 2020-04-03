#include <bits/stdc++.h>

using namespace std;

void Solve(int n) {
    int m = n, b = 0, c = 0;

    while (m > 0) {
        int r = m % 10;

        if (r == 4) {
            b += (int)pow(10, c);
        }

        c++;
        m /= 10;
    }

    cout << n - b << " " << b << endl;
}

int main() {
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        cout << "Case #" << tc << ": ";
        Solve(n);
    }

    return 0;
}
