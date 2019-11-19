#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
ll a[maxn];
int main(int argc,char **argv)
{
    ll sum1 = 0, sum = 0, n;
    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]), sum += a[i];
    sort(a, a+n);
    for(int i = 0; i < n/2; i++)
        sum1 += a[i];
    ll sum2 = 1;
    sum2 = sum - sum1;

    printf("%lld\n", sum2*sum2 + sum1*sum1);
    return 0;
}

