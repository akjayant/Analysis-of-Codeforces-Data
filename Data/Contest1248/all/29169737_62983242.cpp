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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i != n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    long long x = 0, y = 0;
    for (int i = 0; i != n; ++i) {
        if (i % 2 == 0) {
            x += a[r];
            --r;
        }
        else {
            y += a[l];
            ++l;
        }
    }
    cout << x * x + y * y;
    return 0;
}