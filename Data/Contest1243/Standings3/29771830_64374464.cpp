// ContestCoding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using ll = long long;

long long gcd(const long long a, const long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

using namespace std;

int main()
{
    ll q;
    cin >> q;
    for (auto i = 0; i < q; ++i)
    {
        ll n;
        cin >> n;
        vector<int> a(n);
        for (auto j = 0; j < n; ++j)
            cin >> a[j];

        sort(a.begin(), a.end(), [](auto l1, auto l2) { return l1 > l2; });

        auto maxlen = 0;

        for (const auto& b : a)
        {
            if (b > maxlen)
                ++maxlen;
        }

        cout << maxlen;

        if (i < q - 1)
            cout << "\n";
    }
}
