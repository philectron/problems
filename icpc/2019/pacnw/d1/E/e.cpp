#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, long long> freq;
    for (const char& c : s)
        freq[c]++;

    long long sum = 1;
    for (const auto& [c, f] : freq)
        sum *= f + 1;

    cout << sum % 11092019 << endl;

    return 0;
}
