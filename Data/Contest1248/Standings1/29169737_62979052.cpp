#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <string>
#include <iterator>
#include <cmath>

using namespace std;

int main()
{
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long d1 = 0, d2 = 0;
        for (int i = 0; i != n; ++i) {
            int p;
            cin >> p;
            if (p % 2)
                ++d1;
            else
                ++d2;
        }
        int m;
        cin >> m;
        long long j1 = 0, j2 = 0;
        for (int i = 0; i != m; ++i) {
            int q;
            cin >> q;
            if (q % 2)
                ++j1;
            else
                ++j2;
        }
        cout << d1 * j1 + d2 * j2 << '\n';
    }
    return 0;
}