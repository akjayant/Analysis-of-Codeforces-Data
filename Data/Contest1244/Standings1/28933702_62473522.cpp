#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int t,n;
char s[maxn];
int main()
{
    scanf("%d",&t);
    for (int iii=1;iii<=t;++iii)
    {
        scanf("%d\n",&n);
        scanf("%s",s);
        int p1=0,p2=0;
        for (int i=0;i<n;++i)
            if (s[i]=='1')
        {
            p1=i+1;
            break;
        }
        for (int i=n-1;i>=0;--i)
        if (s[i]=='1')
        {

            p2=i+1;
            break;
        }
        int ans;
        if (p1==0 && p2==0) ans=n;
        else
        ans=max(2*(n-p1+1),2*p2);
        printf("%d\n",ans);
    }
    return 0;
}
