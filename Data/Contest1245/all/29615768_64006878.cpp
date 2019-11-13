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
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        int a1 = 0, b1 = 0, c1 = 0;
        for (auto ch : s)
            switch (ch) {
            case 'S':
                ++a1;
                break;
            case 'R':
                ++b1;
                break;
            case 'P':
                ++c1;
                break;
            }
        int a2 = min(a, a1);
        int b2 = min(b, b1);
        int c2 = min(c, c1);
        if (a2 + b2 + c2 >= (s.size() + 1) / 2) {
            cout << "YES\n";
            int a3 = a - a2;
            int b3 = b - b2;
            int c3 = c - c2;
            for (int i = 0; i != s.size(); ++i) {
                if (s[i] == 'S' && a2) {
                    cout << 'R';
                    --a2;
                }
                else if (s[i] == 'R' && b2) {
                    cout << 'P';
                    --b2;
                }
                else if (s[i] == 'P' && c2) {
                    cout << 'S';
                    --c2;
                }
                else if (a3) {
                    cout << 'R';
                    --a3;
                }
                else if (b3) {
                    cout << 'P';
                    --b3;
                }
                else if (c3) {
                    cout << 'S';
                    --c3;
                }
            }
            cout << '\n';
        }
        else
            cout << "NO\n";
    }
    return 0;
}