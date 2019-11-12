#include <cstdio>
#include <algorithm>
using namespace std;

int T,a,b,c;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int ans=0;
        for (int i=0;i<=100;i++)
        {
            for (int j=0;j<=100;j++)
            {
                if (i>a) continue;
                if (i*2+j>b) continue;
                if (j*2>c) continue;
                ans=max(ans,3*i+3*j);
            }
        }
        printf("%d\n",ans);
    }
    getchar(); getchar();
    return 0;
}