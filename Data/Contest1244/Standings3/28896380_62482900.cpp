#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
char str[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %s",&n,str+1);
        int ans = n;
        for(int i=1;i<=n;i++)
        {
            if(str[i]=='1')   ans = max(ans,max(i,n-i+1)*2);
        }
        printf("%d\n",ans);
    }
    return 0;
}
