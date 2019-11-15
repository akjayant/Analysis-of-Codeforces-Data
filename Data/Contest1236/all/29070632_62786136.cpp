#include <bits/stdc++.h>
#define maxn 200000
#define LL long long int
using namespace std;


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        int ans=0;
        if(c>0)
        {
            if(c%2==1)c--;
            int temp=min(b,c/2);
            ans+=temp*3;
            b-=temp;
        }

        if(b>0)
        {
            if(b%2==1)b--;
            int temp=min(a,b/2);
            ans+=temp*3;
        }
        printf("%d\n",ans);
    }
    return 0;
}
