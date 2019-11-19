#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <unordered_map>
#include <map>
#include <deque>

using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
    while(a > 0 && b > 0)
        if(a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}

int main()
{
    int a, b, c, d, k;
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, min1 = 10000, min2 = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); ++j)
        {
            if (s[j] == '1')
            {
                min1 = min(j, min1);
                min2 = max(min2, j);
            }
        }
        if (min1 == 10000)
        {
            cout << n << endl;
            continue;
        }
        int ans1 = 2 * n - 2 * min1;
        int ans2 = 2 * (n - 1 - min2);
        cout << max(ans1, 2 * n - ans2) << endl;
    }
}
