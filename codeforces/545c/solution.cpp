#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tree(n);
    vector<int> occupied(n);
    vector<bool> done(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i].first >> tree[i].second;
        occupied[i] = tree[i].first;
        done[i] = false;
    }

    if (n == 1 || n == 2) {
        cout << n << endl;
        return 0;
    }

    int sum = 2;
    occupied[0] = tree[0].first - tree[0].second;
    done[0] = true;
    occupied[n - 1] = tree[n - 1].first + tree[n - 1].second;
    done[n - 1] = true;
    for (int i = 1, j = 0; i < n / 2 + 1; i++) {
        j = n - i - 1;

        cerr << "i = " << i << ", j = " << j << endl;
        cerr << "occupied[i] = " << occupied[i] << endl;
        if (!done[i]) {
            done[i] = true;
            if (occupied[i - 1] < tree[i].first &&
                tree[i].first - tree[i].second > tree[i - 1].first) {
                cerr << "Fall left on i = " << i << endl;
                sum++;
                occupied[i] = tree[i].first - tree[i].second;
            } else if (occupied[i + 1] > tree[i].first &&
                       tree[i].first + tree[i].second < tree[i + 1].first) {
                cerr << "Fall right on i = " << i << endl;
                sum++;
                occupied[i] = tree[i].first + tree[i].second;
            }
        }

        cerr << "occupied[j] = " << occupied[j] << endl;
        if (!done[j]) {
            done[j] = true;
            if (occupied[j + 1] > tree[j].first &&
                tree[j].first + tree[j].second < tree[j + 1].first) {
                cerr << "Fall left on j = " << j << endl;
                sum++;
                occupied[j] = tree[j].first + tree[j].second;
            } else if (occupied[j - 1] < tree[j].first &&
                       tree[j].first - tree[j].second > tree[j - 1].first) {
                cerr << "Fall right on j = " << j << endl;
                sum++;
                occupied[j] = tree[j].first - tree[j].second;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
