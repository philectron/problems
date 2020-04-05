#include <bits/stdc++.h>

using namespace std;

set<vector<int>> FindSum(vector<int>& summands, int sum) {
    vector<set<vector<int>>> t(sum + 1);

    for (int i = 1; i <= sum; i++) {
        for (auto& s : summands) {
            if (s > i) {
                break;
            } else if (s == i) {
                t[i].insert({s});
            } else {
                for (auto& vs : t[s]) {
                    for (auto& vis : t[i - s]) {
                        vector<int> tmp(vs);
                        tmp.insert(tmp.end(), vis.begin(), vis.end());
                        t[i].insert(tmp);
                    }
                }

                for (auto& vis : t[i - s]) {
                    for (auto& vs : t[s]) {
                        vector<int> tmp(vis);
                        tmp.insert(tmp.end(), vs.begin(), vs.end());
                        t[i].insert(tmp);
                    }
                }
            }
        }
    }

    // // <DEBUG>
    // for (int i = 1; i <= sum; i++) {
    //     cerr << i << " =";
    //     if (t[i].empty()) {
    //         cerr << " EMPTY" << endl;
    //     } else {
    //         cerr << endl;
    //         for (auto& v : t[i]) {
    //             cerr << "  ";
    //             for (auto& s : v) {
    //                 cerr << " + " << s;
    //             }
    //             cerr << endl;
    //         }
    //     }
    // }
    // // </DEBUG>

    return t[sum];
}

void Solve(int n, int k) {
    vector<int> summands(n);
    iota(summands.begin(), summands.end(), 1);
    // cerr << "k = " << k << endl;
    // cerr << "summands =";
    // for (auto& s : summands) {
    //     cerr << " " << s;
    // }
    // cerr << endl;
    set<vector<int>> sums = FindSum(summands, k);
    cerr << "Before trimming" << endl;
    cerr << k << " =" << endl;
    for (auto& v : sums) {
        cerr << "  ";
        for (auto& e : v) {
            cerr << " + " << e;
        }
        cerr << endl;
    }
    for (auto it = sums.begin(); it != sums.end();) {
        if (it->size() != n) {
            it = sums.erase(it);
        } else {
            ++it;
        }
    }
    cerr << "Before trimming" << endl;
    cerr << k << " =" << endl;
    for (auto& v : sums) {
        cerr << "  ";
        for (auto& e : v) {
            cerr << " + " << e;
        }
        cerr << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++) {
        int n, k;
        cin >> n >> k;

        // cout << "Case #" << x << ": ";
        Solve(n, k);
    }

    return 0;
}
