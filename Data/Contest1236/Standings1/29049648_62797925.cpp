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

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j % 2 == 0) {
                cout << j * n - i + 1 << " ";
            } else {
                cout << (j - 1) * n + i << " ";
            }
        }
        cout << endl;
    }
}