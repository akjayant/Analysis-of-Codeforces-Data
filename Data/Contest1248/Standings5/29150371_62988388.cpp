#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>
using namespace std;
long long a[100009];
int main()
{
    long long n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    long long sum1,sum2;
    sum1=sum2=0;
    for(long long i=1;i<=n/2;i++)
    {
        sum1+=a[i];
    }
    for(long long i=n/2+1;i<=n;i++)
    {
        sum2+=a[i];
    }
    sum1=sum1*sum1;sum2=sum2*sum2;
    printf("%lld\n",sum1+sum2);
    return 0;
}
