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
        cin >> a >> b >> c >> d >> k;
        int cnt1 = (a + c - 1) / c;
        int cnt2 = (b + d - 1) / d;
        if (cnt1 + cnt2 <= k)
        {
            cout << cnt1 << " " << cnt2 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
