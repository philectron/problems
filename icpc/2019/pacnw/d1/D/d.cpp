#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, count = 0;
    cin >> a >> b;

    while (a != b) {
        if (a % 2 == 0 && a > b) {
            a /= 2;
        } else {
            a += 1;
        }

        count++;
    }

    cout << count << endl;

    return 0;
}
