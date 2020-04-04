#include <bits/stdc++.h>

using namespace std;

void Solve(int n, int** m) {
    int trace = 0;
    for (int i = 0; i < n; i++) {
        trace += m[i][i];
    }
    int rows = 0, cols = 0;
    vector<pair<unordered_set<int>, bool>> r(n), c(n);
    for (int i = 0; i < n; i++) {
        r[i].second = false;
        c[i].second = false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!r[i].second) {
                if (r[i].first.find(m[i][j]) != r[i].first.end()) {
                    r[i].second = true;
                    rows++;
                } else {
                    r[i].first.insert(m[i][j]);
                }
            }

            if (!c[j].second) {
                if (c[j].first.find(m[i][j]) != c[j].first.end()) {
                    c[j].second = true;
                    cols++;
                } else {
                    c[j].first.insert(m[i][j]);
                }
            }
        }
    }

    cout << trace << " " << rows << " " << cols << endl;
}

int main() {
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++) {
        int n;
        cin >> n;
        int** m = new(nothrow) int*[n];
        for (int i = 0; i < n; i++) {
            m[i] = new(nothrow) int[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        cout << "Case #" << x << ": ";
        Solve(n, m);

        for (int i = 0; i < n; i++) {
            delete[] m[i];
        }
        delete[] m;
    }

    return 0;
}
