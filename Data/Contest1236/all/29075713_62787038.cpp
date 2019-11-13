/*************************************************************************
	> File Name: 2019_10_17_1.cpp
	> Author: z472421519
	> Mail: 
	> Created Time: 2019年10月17日 星期四 21时31分33秒
 ************************************************************************/

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int a,b,c;
    int T;
    scanf("%d",&T);
    while(T--)
    {
    scanf("%d%d%d",&a,&b,&c);
    int ans = 0;
    ans += 3 * min(c / 2,b);
    b -= min(c / 2,b);
    ans += 3 * min(b / 2,a);
    printf("%d\n",ans);
    //return 0;
    }
    return 0;
}
