#include <cstdio>
#include <vector>
using namespace std;
using LL=long long;

LL n,p,d,w;
vector<LL> V;

int main()
{
    scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
    for(LL i=0;i<w-d;i++)
        if((d*(n-i)%(w-d)+w-d)%(w-d)==p%(w-d))
            V.push_back(i);
    for(LL &t:V)
    {
        LL ss=(w*(n-t)-p)/(w-d);
        LL k;
        if(ss<0) {
            k = (-ss) / w + 1;
            if ((-ss) % w == 0)
                k--;
        }
        else
            k=ss/w;
        LL y=-w*k+ss;
        LL z=k*(w-d)+t;
        LL x=n-y-z;
        if(x>=0&&y>=0&&z>=0) {
            printf("%lld %lld %lld", x, y, z);
            return 0;
        }
    }
    printf("-1");
    return 0;
}