#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(long long N)
{
    long long p;
    if(N == 1)
        return false;
    for(p = 2; p * p <= N; ++p)
        if(N % p == 0)
            return false;
    return true;
}

long long pDiv(long long N)
{
    long long p;
    for(p = 2; p * p <= N; ++p)
        if(N % p == 0)
            return p;
}

void Run(long long N)
{
    long long i, j, k, p, a, b, M, rem;
    if(N == 1 || isPrime(N))
    {
        printf("%lld\n", N);
        return;
    }
    
    a = pDiv(N);
    M = a;
    while(M * a <= N)
        M = M * a;
    if(M == N)
    {
        printf("%lld\n", a);
        return;
    }
    else
    {
        printf("1\n");
        return;
    }
}

int main()
{
    long long N;
    scanf("%lld", &N);
    Run(N);
    return 0;
}
