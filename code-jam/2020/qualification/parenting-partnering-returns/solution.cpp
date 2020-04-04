#include <bits/stdc++.h>

using namespace std;

typedef struct Activity {
    int start;
    int end;

    bool operator==(const Activity& rhs) const {
        return start == rhs.start && end == rhs.end;
    }

    bool OverlapsWith(const Activity& rhs) const {
        return !(rhs.start >= end || start >= rhs.end);
    }
} Activity;

bool Overlap(const unordered_set<Activity>& act, const Activity& a) {
    for (const Activity& x : act) {
        if (x.OverlapsWith(a)) {
            return true;
        }
    }
    return false;
}

void Solve(int n, const vector<Activity>& a) {
    string result = "C";
    unordered_set<Activity> c, j;

    c.insert(a[0]);

    for (int i = 1; i < n; i++) {
        bool overlappedC = Overlap(c, a[i]), overlappedJ = Overlap(j, a[i]);
        if (overlappedC && overlappedJ) {
            cout << "IMPOSSIBLE" << endl;
            return;
        } else if (overlappedC) {
            result += 'J';
            j.insert(a[i]);
        } else {
            result += 'C';
            c.insert(a[i]);
        }
    }

    cout << result << endl;
}

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

        cout << "Case #" << x << ": ";
        Solve(n, a);
    }

    return 0;
}
