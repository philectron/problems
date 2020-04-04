#include <bits/stdc++.h>

using namespace std;

typedef struct Activity {
    int start;
    int end;

    bool OverlapsWith(const Activity& rhs) const {
        return !(rhs.start >= end || start >= rhs.end);
    }
} Activity;

bool Overlap(const vector<Activity>& act, const Activity& a) {
    for (const Activity& x : act) {
        if (x.OverlapsWith(a)) {
            return true;
        }
    }
    return false;
}

bool Test(const vector<Activity>& act) {
    for (int i = 0, n = act.size(); i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != i && act[i].OverlapsWith(act[j])) {
                return false;
            }
        }
    }
    return true;
}

string Solve(int n, const vector<Activity>& a) {
    string result = "C";
    vector<Activity> c, j;

    c.push_back(a[0]);

    for (int i = 1; i < n; i++) {
        bool overlappedC = Overlap(c, a[i]), overlappedJ = Overlap(j, a[i]);
        if (overlappedC && overlappedJ) {
            result = "IMPOSSIBLE";

            // <DEBUG>
            c.push_back(a[i]);
            j.push_back(a[i]);
            // </DEBUG>

            break;
        } else if (overlappedC) {
            result += 'J';
            j.push_back(a[i]);
        } else {
            result += 'C';
            c.push_back(a[i]);
        }
    }

    // <DEBUG>
    system("clear");
    string impossible = "IMPOSSIBLE";
    if (result.compare(impossible) == 0) {
        if (Test(c) && Test(j)) {
            result = "BUG";
            cout << "                   BUGGED!" << endl;
        }
    } else {
        if (c.size() + j.size() != n || !Test(c) || !Test(j)) {
            result = "BUG";
            cout << "                   BUGGED!" << endl;
        }
    }
    cout << n << endl;
    for (const Activity& act : a) {
        cout << act.start << " " << act.end << endl;
    }
    // </DEBUG>

    return result;
}

/*
int main() {
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++) {
        int n;
        cin >> n;
        vector<Activity> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].start >> a[i].end;
        }

        cout << "Case #" << x << ": " << Solve(n, a) << endl;
    }

    return 0;
}
*/

// stress test
int main() {
    srand(time(nullptr));

    string result;
    string found = "BUG";

    while (result.compare(found) != 0) {
        int n = rand() % (10 - 2 + 1) + 2;
        vector<Activity> a(n);
        for (int i = 0; i < n; i++) {
            a[i].start = rand() % 1440;
            a[i].end = rand() % (1440 - a[i].start + 1 + 1) + a[i].start + 1;
        }

        result = Solve(n, a);
    }

    return 0;
}
