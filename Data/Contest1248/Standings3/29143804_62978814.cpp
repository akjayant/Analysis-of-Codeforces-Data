/*************************************************************************
	> File Name: 2019_10_20_1.cpp
	> Author: z472421519
	> Mail: 
	> Created Time: 2019年10月20日 星期日 17时05分19秒
 ************************************************************************/

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#define ll long long 
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d",&n);
        ll num1 = 0,num2 = 0;
        for(int i = 1;i <= n;i++)
        {
            int x;
            scanf("%d",&x);
            if(x % 2)
                num1++;
        }
        scanf("%d",&m);
        for(int i = 1;i <= m;i++)
        {
            int x;
            scanf("%d",&x);
            if(x % 2)
                num2++;
        }
        ll ans = num1 * num2 + 1ll * (n - num1) * (m - num2);
        printf("%I64d\n",ans);
    }
    return 0;
}
