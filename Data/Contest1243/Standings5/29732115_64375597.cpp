#include<bits/stdc++.h>

using namespace std;
const int maxnn=1e3+7;
int a[maxnn];
int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        int da=0;
        for(int i=n;i>=1;i--)
        {
           da=max(da,min(n-i+1,a[i]));
        }
        printf("%d\n",da);
    }
    return 0;
}
