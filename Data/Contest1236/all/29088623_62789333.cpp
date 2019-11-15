#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int set = min(b, c / 2);
        b -= set;
        set += min(a, b / 2);
        cout << set * 3 << '\n';
    }
    return 0;
}