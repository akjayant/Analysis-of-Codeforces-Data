#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <random>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
#define LL long long

using namespace std;

const int mod = 1e9+7;
const int maxn = 11234567;

int num[112345];
int pr[112345][2];

int main()
{
    ios::sync_with_stdio(false);

    int t;
    int n;
    LL k;

    scanf("%d%lld", &n, &k);

    for (int i = 0; i < n; ++i) scanf("%d", &num[i]);

    sort(num, num+n);

    int st, en;
    st = en = 0;

    pr[en][0] = num[0];
    pr[en][1] = 0;

    for (int i = 0; i < n; ++i)
    {
        if (num[i] == pr[en][0]) pr[en][1]++;
        else
        {
            pr[++en][0] = num[i];
            pr[en][1] = 1;
        }
    }

    while ((k >= pr[st][1] || k >= pr[en][1]) && st != en)
    {
        if (pr[st][1] > pr[en][1])
        {
            LL dis = pr[en][0] - pr[en-1][0];
            LL cost = pr[en][1];
            LL cut = min(k/cost, dis);
            k -= cost * cut;
            pr[en][0] -= cut;
            if (pr[en][0] == pr[en-1][0])
            {
                pr[en-1][1] += pr[en][1];
                en--;
            }
        }
        else
        {
            LL dis = pr[st+1][0] - pr[st][0];
            LL cost = pr[st][1];
            LL cut = min(k/cost, dis);
            k -= cost * cut;
            pr[st][0] += cut;
            if (pr[st][0] == pr[st+1][0])
            {
                pr[st+1][1] += pr[st][1];
                st++;
            }
        }
    }

    printf("%d\n", pr[en][0] - pr[st][0]);

    return 0;
}
