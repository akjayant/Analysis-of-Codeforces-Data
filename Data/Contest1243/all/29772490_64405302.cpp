#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
#include <assert.h>

#define ll long long

#define sl(n) scanf("%lld", &n)
#define ss(n) scanf("%s", n)
#define sf(n) scanf("%lf", &n)

#define PI 2*acos(0.0)
#define INF (1LL<<62)

#define pll pair<ll,ll>

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define srt(v) sort(v.begin(), v.end())
using namespace std;

bool isPrime[1000011];

int main()
{
  //  freopen("input.txt", "r", stdin);

    ll n, i, j, k, x, y, z, cs, ts;

    while(sl(n) != EOF)
    {
        for (i = 2; i <= 1000010; i += 2)
        {
            if (isPrime[i] == 0)
            {
                for (j = i*i; j <= 1000010; j += 2*i)
                {
                    isPrime[j] = 1;
                }
            }
            if (i == 2)
                i = 1;
        }

        ll temp = n;

        ll cnt = 0;

        for (i = 2; i*i <= n; i++)
        {
            if (isPrime[i] == 0 && n%i == 0)
            {
                x = i;
                cnt++;
                while(temp%i == 0)
                    temp /= i;
            }
        }

        if (temp != 1)
        {
            x = n;
            cnt++;
        }

   //     cout << cnt << " " << x << endl;

        if (cnt == 1)
        {
            if (x == n)
                printf("%lld\n", n);
            else
                printf("%lld\n", x);
        }
        else printf("1\n");
    }

    return 0;
}
