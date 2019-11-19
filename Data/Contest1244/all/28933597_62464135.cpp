#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cassert>
#include <unordered_map>

#define ll long long

using namespace std;


int main() {
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int pp = (a + c - 1) / c;
        int cc = (b + d - 1) / d;
        int total = pp + cc;
        if (total <= k) {
            cout << pp << " " << cc << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}
