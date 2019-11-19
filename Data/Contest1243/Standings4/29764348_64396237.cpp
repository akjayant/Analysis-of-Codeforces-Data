#include <bits/stdc++.h>

using namespace std;

int main()
{
  	iostream::sync_with_stdio(0); cin.tie(0);
    long long n, ans, g;
    vector <long long> ara;
    cin >> n;
    ans = n;
    for (long long i = 2ll ; i * i <= n ; i++)
    {
        if (n % i == 0)
        {
            ara.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        ara.push_back(n);
    if (ara.size() == 1)
        ans = ara[0];
    else if (ara.size() > 1)
    {
        g = __gcd(ara[0], ara[1]);
        for (int i = 2 ; i < ara.size() ; i++)
            g = __gcd(g, ara[i]);
        ans = g;
    }
    cout << ans;
    return 0;
}
