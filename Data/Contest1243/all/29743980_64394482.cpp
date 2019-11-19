#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> v;
long long gcd;
int main()
{
    cin >>n;
    long long sq=sqrt(n);
    for (long long i=2;i<=sq;i++)
    {
        if (n%i==0)
        {
            gcd=__gcd(gcd,i);
            long long x=n/i;
            gcd=__gcd(gcd,x);
        }
    }
    if (!gcd)
        gcd=n;
    cout <<gcd;
    return 0;
}
