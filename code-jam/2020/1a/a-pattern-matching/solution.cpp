#include <bits/stdc++.h>

using namespace std;

void Solve(int n, vector<string>& p) {
    sort(p.begin(), p.end(), [](string& x, string& y) {
        return x.length() < y.length();
    });
    for (auto& s : p)
        s.erase(0, 1);

    string result;

    int k = 0;
    while (true) {
        if (k == n - 1) {
            result.insert(0, p[k]);
            break;
        }
        char tail = p[k].back();
        string stail;
        stail += tail;
        for (int i = k + 1; i < n; i++) {
            if (p[i].back() != tail) {
                cout << "*" << endl;
                return;
            }
            p[i].pop_back();
        }
        result.insert(0, 1, tail);
        p[k].pop_back();
        if (p[k].length() == 0)
            k++;
    }

    cout << result << endl;
}

int main() {
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++) {
        int n;
        cin >> n;
        set<string> ps;
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            ps.insert(tmp);
        }
        vector<string> p(ps.begin(), ps.end());

        cout << "Case #" << x << ": ";
        Solve(p.size(), p);
    }

    return 0;
}
