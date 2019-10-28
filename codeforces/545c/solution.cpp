#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tree(n);
    vector<int> occupied(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i].first >> tree[i].second;
        occupied[i] = tree[i].first;
    }

    if (n == 1 || n == 2) {
        cout << n << endl;
        return 0;
    }

    int sum = 2;
    occupied[0] = tree[0].first - tree[0].second;
    occupied[n - 1] = tree[n - 1].first + tree[n - 1].second;
    for (int i = 1, j = 0; i < n / 2 + 1; i++) {
        if (occupied[i - 1] < tree[i].first &&
            tree[i].first - tree[i].second > tree[i - 1].first) {
            sum++;
            occupied[i] = tree[i].first - tree[i].second;
        } else if (occupied[i + 1] > tree[i].first &&
                   tree[i].first + tree[i].second < tree[i + 1].first) {
            sum++;
            occupied[i] = tree[i].first + tree[i].second;
        }

        j = n - i - 1;

        if (j > i) {
            if (occupied[j + 1] > tree[j].first &&
                tree[j].first + tree[j].second < tree[j + 1].first) {
                sum++;
                occupied[j] = tree[j].first + tree[j].second;
            } else if (occupied[j - 1] < tree[j].first &&
                       tree[j].first - tree[j].second > tree[j - 1].first) {
                sum++;
                occupied[j] = tree[j].first - tree[j].second;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
