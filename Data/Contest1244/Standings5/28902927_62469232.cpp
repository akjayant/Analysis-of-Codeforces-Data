#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=300050;

char s[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='1')
            {
                ans=max(ans,max(n-i+1,i));
            }
        }
        printf("%d\n",max(n,ans*2));
    }
    return 0;
}
