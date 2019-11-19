#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    vector<long long> arr;

    cin >> n;
    arr.resize(n);
    for (auto &i : arr) cin >> i;
    sort(arr.begin(), arr.end(), greater<>());
    long long s1 = 0, s2 = 0;
    int i = 0;
    for (auto num : arr) {
        if (i < (n - 1) / 2 + 1)
            s1 += num;
        else
            s2 += num;
        ++i;
    }

    cout << s1 * s1 + s2 * s2 << endl;

    return 0;
}