#include <cstdio>
#include <algorithm>
using namespace std;

int T,a,b,c,d,k;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int x=a/c+(a%c!=0);
        int y=b/d+(b%d!=0);
        if (x+y>k) printf("-1\n");
        else printf("%d %d\n",x,y);
    }
    getchar(); getchar();
    return 0;
}