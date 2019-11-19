#include <bits/stdc++.h>

using namespace std;
long long gcd(long long a , long long b)
{
    if(b == 0)
        return a;
    else
        return gcd(b , a % b);
}
int main()
{
    long long n , ans;
    cin >> n;
    ans = n;
    for(int i = 2; i <= sqrt(n); i ++)
    {
        if(n % i == 0)
        {
             ans = gcd(ans , i);
             ans = gcd(ans , n / i);
        }
    }
    cout << ans;
    return 0;
}
/*
10

1 2 3 4 5 6 7 8 9 10

*/
