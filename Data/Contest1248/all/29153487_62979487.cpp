#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <bitset>

using namespace std;
vector<int> plk;

int main()
{

    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%i", &t);
        plk.push_back(t);
    }
    sort(plk.begin(), plk.end());
    int half1 = n/2;
    int64_t dx = 0;
    int64_t dy = 0;
    for (int i = 0; i < half1; i++)
        dx += plk[i];
    for (int i = half1; i < n; i++)
        dy += plk[i];

    int64_t ans = (dx * dx) + dy * dy;
    printf("%lld", ans);
}

