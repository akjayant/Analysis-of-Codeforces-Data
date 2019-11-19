#include <iostream>
#include <vector>

using namespace std;

long long gcd (long long a, long long b, long long & x, long long & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main()
{
    long long n, p, w, d;
    cin >> n >> p >> w >> d;
    vector<long long> ring(1e5 + 1, -1);
    for(int i = 0; d * i <= p && i <= w; i++)
    {
        //cout << i << ' ' << (p-d*i)%w << "\n";
        if(ring[(p-d*i)%w] == -1)
            ring[(p - d * i) % w] = i;
    }
    long long x, y, z;
    if(ring[0] == -1)
    {
        cout << -1;
        return 0;
    }
    y = ring[0];
    x = (p - d * y) / w;
    z = n - x - y;
    if (z < 0)
    {
        cout << -1;
        return 0;
    }
    else
        cout << x << ' ' << y << ' ' << z;
    return 0;
}
