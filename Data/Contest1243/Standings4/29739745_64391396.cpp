#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    ll n, mid = -1, sum = 0;
    cin >> n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum++;
            mid = i;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1)
    {
        sum++; mid = n;
    }
    if (sum != 1)
        mid = 1;
    cout << mid << endl;
}
