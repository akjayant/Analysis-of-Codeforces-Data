#include <bits/stdc++.h>
using namespace std;
int main()
{
   char str[2000];
    int ts;
    cin>>ts;
    while(ts--){
    int n;
        scanf("%d",&n);
        int mi=300000,ma=0;
        scanf("%s",str);
        for(int i=1;i<=n;i++)
        {
        int l;
            l=str[i-1]-48;
            if(l==0)continue;
            //scanf("%d",&l);
            mi=min(mi,i);
            ma=max(ma,i);
        }
        if(mi>n&&ma<1)
        {
            printf("%d\n",n);
            continue;
        }
        int ans=max(2*(n-mi+1),2*(ma));
        ans=max(ans,n);
        printf("%d\n",ans);
    }
}
