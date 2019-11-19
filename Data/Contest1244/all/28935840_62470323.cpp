#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        char s[1010]={};
        int n,ans;
        scanf("%d%s",&n,s),ans=n;
        for (int i=0; i<n; ++i)
            if (s[i]=='1')
                ans=max(ans,max(i+1,n-i)*2);
        printf("%d\n",ans);
    }
    return 0;
}
