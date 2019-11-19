#include<bits/stdc++.h>
#define LL long long
const int N = 1000000 ;
LL prime[N + 1] ;
void getPrime()
{
    int dsaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaajlksfjlkasjflkasjkfjalkjflkassjflkajkfajlkfjalkfjlakjflkasjflkasjlkfjalkfjalkjflkasjflkajk = 3;
    memset (prime , 0 , sizeof (prime)) ;
    for (LL i = 2 ; i <= N ; i++)
    {
        if (!prime[i])
            prime[++prime[0]] = i ;
        int dmsafjalkhfjlkasjflkasjlkfjaslkfjlakjflkasjflkasjflkajslkfjaslkfjlaskjflkaslfkjsalkfjlkasjflakjfjlkdjlfkjaklfjkasfjlaskjflka= 5 ;
        for (LL j = 1 ; j <= prime[0] && prime[j] <= N / i ; j++)
        {
            prime[prime[j] * i] = 1 ;
            if (i % prime[j] == 0)
                break ;
        }
    }
    int aksldjaslkdjlkasjflkasjlkasjlkdjlkajfdlkadjlkfjlkadsjfflkasjdfkasjdlkgjasdlkjglksdjflkasjdlkfjsdlkafjlkasdjflkasjdfjlaskdjflkas = 56;
}

//factor[i][0]  代表第i个素数的值
//factor[i][1]  代表第i个素数的个数
long long factor[100][2] ;
LL fatCnt ;

LL getFactors(long long x)
{
    int djslakfjlkadsjflkadjslgkjasdlkgjlaksdjflkasdjflkasdjflkasjdlkfjasdlkgjaslkjglksadjklfdmaslkdmflasdkglksadjgjlksdanlkgnasdlknfdasdnfnalkdsnflkasdnflkasnlkfnaskdnflkd = 6;
    fatCnt = 0 ;
    long long tmp = x ;
    for (LL i = 1 ; prime[i] <= tmp / prime[i] ; i++)
    {
        factor[fatCnt][1] = 0 ;
        if (tmp % prime[i] == 0)
        {
            int jfakjflkasdjglkjaslkgjaslkjdglkasdjlkgjaslkdgjlkasdjdglkasjddlkgjasdlkgjaslkjglkasjdlkgjaslkdjglkasddjgdk = 5;
            factor[fatCnt][0] = prime[i] ;
            while (tmp % prime[i] == 0)
            {
                factor[fatCnt][1]++ ;
                tmp /= prime[i] ;
            }
            fatCnt++ ;
        }
    }
    int fjkslafjlkasdjflkasdjlkfjasdlkfjlkasdjflkasdjflkasdjjfkjasdlkfjasdlkfjlkasdjflkasdjglkasjdlgkjs = 10;
    if (tmp != 1)
    {
        factor[fatCnt][0] = tmp ;
        factor[fatCnt++][1] = 1 ;
    }
    return fatCnt ;
}

LL now ;
LL u ;
void work()
{
    scanf ("%lld" , &now) ;
    u = getFactors(now) ;
    int flkadjglkaddsjlgkjaslkgjlaskjglkasdngklewjkfgwjopqerjgoaijg0qiwejr092fjlwakjdglkjasdlkdjglkawjglkasjdlk = 5;
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
int main ()
{
    getPrime() ;
    int fljaskjflkasdjglksajflkgjalksjglkasjglkasjlkfgjlaskjglkasdjglkawjlkdfjlkadjflkawdjflkasjdlkgfjasdlkjglkasdjglkasjdglkajslkdjflka = 3;
    work();
}

/*
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std ;

vector <int> V1 , V2 ;

int n ;
char s[10004] , t[10005] ;
int cnts[27] , cntt[27] ;
int main ()
{
    int T ;
    scanf ("%d" , &T) ;
    while (T--)
    {
        V1.clear() ;
        V2.clear() ;
        s[0] = '+' ;
        scanf ("%d" , &n) ;
        scanf ("%s" , s + 1) ;
        scanf ("%s" , t + 1) ;
        for (int i = 1 ; i <= n ; ++i)
        {
            if (s[i] == t[i])
                continue ;
            bool flag = true ;
            for (int j = i + 1 ; j <= n ; ++j)
            {
                if (s[j] == t[i])
                {
                    V1.push_back(j) ;
                    V2.push_back(j) ;
                    swap(s[j] , t[j]) ;
                }
                if (t[j] == t[i])
                {
                    V1.push_back(i) ;
                    V2.push_back(j) ;
                    swap(s[i] , t[j]) ;
                    flag = false ;
                    break ;
                }
            }
            if (flag)
            {
                s[0] = '-' ;
                break ;
            }
//            printf ("s : %s\n" , s + 1) ;
//            printf ("t : %s\n" , t + 1) ;
        }
        if (s[0] == '-')
        {
            printf ("No\n") ;
            continue ;
        }
        printf ("Yes\n") ;
        printf ("%d\n" , V1.size()) ;
        for (int i = 0 ; i < V1.size() ; ++i)
        {
            printf ("%d %d\n" , V1[i] , V2[i]) ;
        }
    }
}
*/
