#include <bits/stdc++.h>

using namespace std;

void Backtrack(int** m, int n, int k, int r, int c) {
    int backup = m[r][c];
    for (int i = 1; i <= n; i++) {
        m[r][c] = i;
        int downR = r + 1, downC = c + 1;

    }
}

void Solve(int n, int k) {
    int** m = new(nothrow) int*[n];
    for (int i = 0; i < n; i++) {
        m[i] = new(nothrow) int[n];
    }

    Backtrack(m, n, k, 0, 0);

    for (int i = 0; i < n; i++) {
        delete[] m[i];
    }
    delete[] m;
}

int main() {
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++) {
        int n, k;
        cin >> n >> k;

        cout << "Case #" << x << ": ";
        Solve(n, k);
    }

    return 0;
}
