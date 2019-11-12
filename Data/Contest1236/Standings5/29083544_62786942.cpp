#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
const int maxn=1e5+10;
//int a[maxn];
int main()
{
    int n,a,b,c,ans;
    scanf("%d",&n);
    while(n--)
    {
        ans=0;
        scanf("%d%d%d",&a,&b,&c);
        if(b>=c/2)
        {
            ans+=c/2*3;
            b-=c/2;
            if(a>=b/2)
                ans+=b/2*3;
            else
                ans+=a*3;
        }
        else
            ans+=b*3;
        printf("%d\n",ans);
    }
    return 0;
}
