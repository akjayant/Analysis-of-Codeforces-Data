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

int n;

inline void incr(int& i)
{
    i = (i < n - 1) ? i + 1 : 0;
}

int main()
{
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    string s;
    cin >> s;
    int maxx = 0, imax = 0, jmax = 0;
    for (int i = 0; i != n - 1; ++i)
        for (int j = (i == 0) ? 0 : i + 1; j != n; ++j) {
            if ((i != 0 || j != 0) && s[i] == s[j])
                continue;
            swap(s[i], s[j]);
            int k = 0;
            int w = 0;
            int cnt = 0;
            
            int minn = 0;
            int kminn = -1;
            while (k != n) {
                if (s[k] == '(') {
                    ++w;
                }
                else if (s[k] == ')') {
                    --w;
                    if (w < minn) {
                        minn = w;
                        kminn = k;
                    }
                }
                ++k;
            }
            k = kminn;
            incr(k);
            int m = k;
            bool flag = true;
            do {
                if (s[k] == '(') {
                    ++w;
                }
                else if (s[k] == ')') {
                    --w;
                    if (w == 0) {
                        ++cnt;
                    }
                    else if (w < 0) {
                        flag = false;
                        break;
                    }
                }
                incr(k);
            } while (k != m);
            
            if (!flag || w != 0) {
                swap(s[i], s[j]);
                continue;
            }
            if (cnt > maxx) {
                maxx = cnt;
                imax = i;
                jmax = j;
            }
            swap(s[i], s[j]);
        }
    cout << maxx << '\n' << imax + 1 << ' ' << jmax + 1;
    return 0;
}