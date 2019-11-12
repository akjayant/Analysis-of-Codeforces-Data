#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int m,n,t,ans;
int a[N];

int main()
{
    // freopen("data.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);ans=1e9;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1,greater<int>());
        int i;
        for(i=1;i<=n&&i<=a[i];i++);
        printf("%d\n",i-1);        
    }
}
