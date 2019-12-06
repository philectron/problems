#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count = 0;

    void backtracking(int n, int r, vector<bool>& rows, vector<bool>& cols, vector<bool>& d1, vector<bool>& d2) {
        if (r == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; c++) {
            int id1 = d1.size() - 1 + c - r;
            int id2 = r + c;

            if (rows[r] || cols[c] || d1[id1] || d2[id2])
                continue;

            rows[r] = true;
            cols[c] = true;
            d1[id1] = true;
            d2[id2] = true;

            backtracking(n, r + 1, rows, cols, d1, d2);

            rows[r] = false;
            cols[c] = false;
            d1[id1] = false;
            d2[id2] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> rows(n, false);
        vector<bool> cols(n, false);
        vector<bool> d1(2 * n - 1, false);
        vector<bool> d2(2 * n - 1, false);

        backtracking(n, 0, rows, cols, d1, d2);

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    Solution s;
    cout << s.totalNQueens(n) << endl;
}
