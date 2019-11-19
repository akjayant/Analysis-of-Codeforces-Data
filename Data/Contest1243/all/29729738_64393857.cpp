#include <stdio.h>
#include <string.h>

//素数筛选和合数分解
#define LL long long
const int MAXN = 1000000 ;
LL prime[MAXN + 1] ;
void getPrime()
{
    memset (prime , 0 , sizeof (prime)) ;
    for (LL i = 2 ; i <= MAXN ; ++i)
    {
        if (!prime[i])
            prime[++prime[0]] = i ;
        for (LL j = 1 ; j <= prime[0] && prime[j] <= MAXN / i ; ++j)
        {
            prime[prime[j] * i] = 1 ;
            if (i % prime[j] == 0)
                break ;
        }
    }
}

//factor[i][0]  代表第i个素数的值
//factor[i][1]  代表第i个素数的个数
long long factor[100][2] ;
LL fatCnt ;

LL getFactors(long long x)
{
    fatCnt = 0 ;
    long long tmp = x ;
    for (LL i = 1 ; prime[i] <= tmp / prime[i] ; ++i)
    {
        factor[fatCnt][1] = 0 ;
        if (tmp % prime[i] == 0)
        {
            factor[fatCnt][0] = prime[i] ;
            while (tmp % prime[i] == 0)
            {
                factor[fatCnt][1]++ ;
                tmp /= prime[i] ;
            }
            fatCnt++ ;
        }
    }
    if (tmp != 1)
    {
        factor[fatCnt][0] = tmp ;
        factor[fatCnt++][1] = 1 ;
    }
    return fatCnt ;
}

LL now ;
LL u ;
int main ()
{
    getPrime() ;
    scanf ("%lld" , &now) ;
    u = getFactors(now) ;
    if (u == 0)
    {
        printf ("%lld" , now) ;
    }
    else if (u == 1)
    {
        printf ("%lld" , factor[0][0]) ;
    }
    else
        printf ("1") ;
}
