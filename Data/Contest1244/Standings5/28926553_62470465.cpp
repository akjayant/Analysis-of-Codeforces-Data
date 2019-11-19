#include <cstdio>
#include <algorithm>
using namespace std;

int T,n;
char s[1010];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        int ans=n;
        for (int i=1;i<=n;i++)
        {
            if (s[i]=='1') ans=max(ans,2*max(i,n-i+1));
        }
        printf("%d\n",ans);
    }
    getchar(); getchar();
    return 0;
}