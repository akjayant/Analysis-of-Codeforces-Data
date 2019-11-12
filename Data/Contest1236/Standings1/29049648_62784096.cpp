#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std;
typedef long long int lli;
typedef long double ld;

int main() {
    // ifstream cin("biconv.in");
    // ofstream cout("biconv.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        int sec = min(z / 2, y);
        y -= sec;
        int fir = min(y / 2, x);
        cout << fir * 3 + sec * 3 << endl;
    }
}