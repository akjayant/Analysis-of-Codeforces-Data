#include <iostream>
#include <cmath>
#include <random>
#include <cassert>
#include <iomanip>
#include <set>
#include <map>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#define int long long
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (gcd(a, b) == 1) {
            cout << "Finite" << endl;
        } else {
            cout << "Infinite" << endl;
        }
    }
}