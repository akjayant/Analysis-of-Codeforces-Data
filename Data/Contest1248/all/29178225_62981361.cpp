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

long long n, a[100010], s1, s2, i;

int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    scanf("%I64d", &n);
    for(i = 0; i < n; i++)
        scanf("%I64d", &a[i]);

    sort(a, a + n);

    s1 = s2 = 0;
    for(i = 0; i < n / 2; i++)
        s1 += a[i];
    for(; i < n; i++)
        s2 += a[i];

    cout << s1 * s1 + s2 * s2 << endl;

    return 0;
}











