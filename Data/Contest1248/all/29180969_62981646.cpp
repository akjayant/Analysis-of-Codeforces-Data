#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a=0,b=0,x;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x&1)a++;
            else b++;
        }
        ll ans=0;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            if(x&1)ans+=a;
            else ans+=b;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}