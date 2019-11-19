/* GCC */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>

#define X first
#define Y second
#define mp(a, b) make_pair((a), (b))

using namespace std;

int t, n, m, i, j, k;
long long a1, b1, a2, b2;

int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    for(cin >> t; t > 0; t--)
    {
        a1 = a2 = b1 = b2 = 0;

        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> k;
            if(k % 2 == 0)
                a1++;
            else
                a2++;
        }

        cin >> m;
        for(i = 0; i < m; i++)
        {
            cin >> k;
            if(k % 2 == 0)
                b1++;
            else
                b2++;
        }

        cout << a1 * b1 + a2 * b2 << endl;
    }

    return 0;
}











