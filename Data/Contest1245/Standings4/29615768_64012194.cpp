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

const int mod = 1000 * 1000 * 1000 + 7;

int fib[100001];

int main()
{
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i <= 100000; ++i)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    string s;
    cin >> s;
    char prev = '0';
    int k = 1;
    long long ans = 1;
    for (auto c : s) {
        if (c == 'm' || c == 'w') {
            cout << 0;
            return 0;
        }
        else if (c == prev) {
            ++k;
        }
        else if (prev == 'n' || prev == 'u') {
            ans = (ans * fib[k]) % mod;
            k = 1;
        }
        else
            k = 1;
        prev = c;
    }
    if (prev == 'n' || prev == 'u') {
        ans = (ans * fib[k]) % mod;
    }
    cout << ans;
    return 0;
}