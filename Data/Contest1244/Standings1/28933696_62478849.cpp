#include <bits/stdc++.h>
using namespace std;

long long gcd (long long a, long long b)
{
    if(a < b)
        swap(a,b);
    if (b == 0)
        return a;
    return gcd(a % b, b);
}
int main()
{
    long long n,p,w,d;
    cin >> n >> p >> w >> d;
    long long g = gcd(w,d);
    if(p % g != 0)
    {
        cout << -1;
        return 0;
    }
    p /= g;
    w /= g;
    d /= g;
    long long x0 = -1;
    long long y0 = -1;
    for(int i = 0; i < d; i++)
        if( (p - i * w) % d == 0)
            x0 = i;
    for(int i = 0; i < w; i++)
        if( (p - i * d) % w == 0)
            y0 = i;
    if(x0  == -1 || y0 == -1)
    {
        cout << -1;
        return 0;
    }

    long long q = p - x0*w - y0*d;
    if(q % (w*d) != 0)
    {
        cout << -1;
        return 0;
    }
    q /= w*d;
    long long z;
    long long z0;
    long long m = n - x0 - y0- q*d;
    if(m < 0)
    {
        cout << -1;
        return 0;
    }
    if(w == d)
        z = m;
    else
    {
        long long z0 = m % (w - d);
        if( (m - z0)/(w - d) > q)
        {
            z = m - q*(w - d);
        }
        else{
            z = z0;

        }
    }
    long long l = (m - z)/(w - d);
    long long k = q - l;
    long long x = k*d + x0;
    long long y = l*w + y0;
    if(x < 0 || y < 0 || z < 0)
    {
        cout << -1;
        return 0;
    }
    cout << x << ' ' << y << ' ' << z  << endl;
    //cout << x *w + y * d << ' ' << p << endl;
    //cout << x + y + z << ' ' << n;

}
