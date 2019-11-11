#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int t, x, y;
bool isAns;
int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> x >> y;
        isAns = false;
        int a = max(x, y);
        int b = min(x, y);
        for (int j = 2; j <= b; ++j) {
            if (a % j == 0 && b % j == 0) {
                cout << "Infinite" << endl;
                isAns = true;
                break;
            }
        }
        if (!isAns)
            cout << "Finite" << endl;
    }
    return 0;
}