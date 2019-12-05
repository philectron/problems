#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> p(3);
    int n;

    cin >> n >> p[0] >> p[1] >> p[2];

    vector<int> r(n + 1, 0);

    for (int i = 1; i <= n; i++)
        for (const auto& piece : p)
            if (i >= piece)
                r[i] = max(r[i], i - piece > 0 && r[i - piece] == 0 ? 0 : r[i - piece] + 1);

    cout << r[n] << endl;

    return 0;
}
