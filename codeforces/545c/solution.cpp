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

        if (!done[i]) {
            done[i] = true;
            if (tree[i].first - tree[i].second > max(tree[i - 1].first, occupied[i - 1])) {
                sum++;
                occupied[i] = tree[i].first - tree[i].second;
            } else if (tree[i].first + tree[i].second < min(tree[i + 1].first, occupied[i + 1])) {
                sum++;
                occupied[i] = tree[i].first + tree[i].second;
            }
        }

        if (!done[j]) {
            done[j] = true;
            if (tree[j].first + tree[j].second < min(tree[j + 1].first, occupied[j + 1])) {
                sum++;
                occupied[j] = tree[j].first + tree[j].second;
            } else if (tree[j].first - tree[j].second > max(tree[j - 1].first, occupied[j - 1])) {
                sum++;
                occupied[j] = tree[j].first - tree[j].second;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
