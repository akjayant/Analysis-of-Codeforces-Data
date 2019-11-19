/*************************************************************************
	> File Name: 2019_10_20_2.cpp
	> Author: z472421519
	> Mail: 
	> Created Time: 2019年10月20日 星期日 17时18分11秒
 ************************************************************************/

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#define MAXN 100003
using namespace std;

long long a[MAXN];
int main()
{
    long long sum = 0,sum1 = 0;
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld",&a[i]);
        sum += a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n / 2;i++)
        sum1 += a[i];
    long long ans = sum1 * sum1 + (sum - sum1) * (sum - sum1);
    cout << ans << endl;
    return 0;
}
