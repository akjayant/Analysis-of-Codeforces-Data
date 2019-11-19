#include <bits/stdc++.h>
using namespace std;
char s[1005];
int n;
int L,R;

int main()
{
    int T;cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        L=R=0;
        for(int i=1;i<=n;++i)
        {
            if(s[i]=='1')
            {
                L=i;
                break;
            }
        }
        if(L==0)
        {
            printf("%d\n",n);
            continue;
        }
        for(int i=n;i>=1;--i)
        {
            if(s[i]=='1')
            {
                R=i;
                break;
            }
        }
        int ans=max(R*2,(n-L+1)*2);
        printf("%d\n",ans);
    }
    return 0;
}
