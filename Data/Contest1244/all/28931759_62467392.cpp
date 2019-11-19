#include <cstdio>
using namespace std;

int T,a,b,c,d,k,x,y;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        x=(a-1)/c+1;
        y=k-x;
        if(y>=0&&y*d>=b)
            printf("%d %d\n",x,y);
        else
            puts("-1");
    }
    return 0;
}