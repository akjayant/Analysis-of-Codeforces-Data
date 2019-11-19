/*jai mata di
let's rock*/
#include<bits/stdc++.h>
using namespace std;
const int N=1004;
char s[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int i;
        int f=0;
        int ans=0;
        int cnt=0;
        for(i=1;i<=n;i++)
        {
            if(s[i]=='1'){
                cnt+=2;
                f=1-f;
            }
            else cnt++;
        }
        ans=max(ans,cnt);
        cnt=0;
        for(i=1;i<=n;i++)
        {
            if(s[i]=='1')
              cnt=max(cnt,2*i);
        }
        ans=max(ans,cnt);
        cnt=0;
        for(i=n;i>=1;i--)
        {
            if(s[i]=='1')
                cnt=max(cnt,2*(n-i+1));
        }
        ans=max(ans,cnt);
        printf("%d\n",ans);
    }
    return 0;
}
