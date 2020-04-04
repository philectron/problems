#include <bits/stdc++.h>

using namespace std;

string Solve(vector<array<int, 3>>& a) {
    int n = a.size();

    sort(a.begin(), a.end(), [](array<int, 3>& x, array<int, 3>& y) {
        return x[0] < y[0];
    });

    string result(n, ' ');
    int ce = a[0][1], je = 0;
    result[a[0][2]] = 'C';

    for (int i = 1; i < n; i++) {
        if (a[i][0] >= ce) {
            result[a[i][2]] = 'C';
            ce = a[i][1];
        } else if (a[i][0] >= je) {
            result[a[i][2]] = 'J';
            je = a[i][1];
        } else {
            return "IMPOSSIBLE";
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++) {
        int n;
        cin >> n;
        vector<array<int, 3>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
            a[i][2] = i;
        }

        cout << "Case #" << x << ": " << Solve(a) << endl;
    }

    return 0;
}
