#include <cstdio>
#include <iostream>
using namespace std;
int cnt[10005];
int aftersort[100005];
int main()
{
    int n;
    scanf("%d", &n);
    int num;
    int cntx = 0;
    int cnty = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num);
        cnt[num]++;
    }
    int tot=0;
    for (int i = 1; i <= 10000; i++)
    {
        while (cnt[i])
        {
            aftersort[++tot] = i;
            cnt[i]--;
        }
    }
    for(int i=1;i<=n/2;i++) cntx+=aftersort[i];
    for(int i=n;i>n/2;i--) cnty+=aftersort[i];
    printf("%I64d\n",(long long) cntx*cntx+(long long) cnty*cnty);
}