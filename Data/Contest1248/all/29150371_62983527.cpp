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

int main()
{
    int t;
    scanf("%d",&t);
    int m,n,m1,m2,n1,n2,a;
    while(t--)
    {
        scanf("%d",&m);
        m1=m2=n1=n2=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a);
            if(a%2) m1++;
            else m2++;
        }
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if(a%2) n1++;
            else n2++;
        }
        long long sum=(long long)n1*m1+(long long)n2*m2;
        printf("%lld\n",sum);
    }
    return 0;
}
