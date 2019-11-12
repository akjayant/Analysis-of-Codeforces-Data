#include <cstdio>
#include <algorithm>
#define M 1000000007
using namespace std;

long long n,m;

long long quick_pow(long long a,long long k,long long p)
{
    long long re=1;
    while (k)
    {
        if (k&1) re=(re*a)%p;
        k>>=1;
        a=(a*a)%p;
    }
    return re;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    printf("%lld",quick_pow((quick_pow(2,m,M)-1+M)%M,n,M));
    getchar(); getchar();
    return 0;
}