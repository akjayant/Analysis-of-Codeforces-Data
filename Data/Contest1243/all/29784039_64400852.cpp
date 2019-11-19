#include <bits/stdc++.h>
typedef long long ll;

using namespace std ;
const int maxn=1e6+10;
vector <int> vk , jkld12 ;
int tttttttttttttttttttttttttttt=0;
int gioyhrgihhhhhihihihihihihihi=12;
int hhhhhhhhhhhhhhhhhhhhhhhhhhh=15;
ll wjojfjiojsdoid[maxn + 1] ;
int n ;
char s[maxn] , t[maxn] ;
int hhhhhhhhhhhhjjjjjjjjjjjj=0;
int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa=12;
int cnts[27] , cntt[27] ;
void getwjojfjiojsdoid()
{if(n) hhhhhhhhhhhhjjjjjjjjjjjj++;
    memset (wjojfjiojsdoid , 0 , sizeof (wjojfjiojsdoid)) ;if(n) hhhhhhhhhhhhjjjjjjjjjjjj++;
    for (ll i = 2 ; i <= maxn ; ++i)
    {
        if (!wjojfjiojsdoid[i])
            wjojfjiojsdoid[++wjojfjiojsdoid[0]] = i ;
        for (ll j = 1 ; j <= wjojfjiojsdoid[0] && wjojfjiojsdoid[j] <= maxn / i ; ++j)
        {wjojfjiojsdoid[wjojfjiojsdoid[j] * i] = 1 ;if (i % wjojfjiojsdoid[j] == 0)
                break ;}if(n) hhhhhhhhhhhhjjjjjjjjjjjj++;
    }
}
long long hopjji[100][2] ;
ll fatCnt ;
ll gethopjjis(long long x)
{
    fatCnt = 0 ;if(n) hhhhhhhhhhhhjjjjjjjjjjjj++;
    long long tmp = x ;
    for (ll i = 1 ; wjojfjiojsdoid[i] <= tmp / wjojfjiojsdoid[i] ; ++i)
    {
        hopjji[fatCnt][1] = 0 ;
        if (tmp % wjojfjiojsdoid[i] == 0)
        {
            hopjji[fatCnt][0] = wjojfjiojsdoid[i] ;while (tmp % wjojfjiojsdoid[i] == 0)
            {hopjji[fatCnt][1]++ ;
                tmp /= wjojfjiojsdoid[i] ;
            }
            fatCnt++ ;
        }
    }if(n) hhhhhhhhhhhhjjjjjjjjjjjj++;
    if (tmp != 1)
    {
        hopjji[fatCnt][0] = tmp ;
        hopjji[fatCnt++][1] = 1 ;
   }//if(n) hhhhhhhhhhhhjj jjjjjjjjjj++;
    return fatCnt ;
}

ll now,u;
//int hhhhhhhhhhhhjjjjjjjjjjjj=12;
void solv(){
   /* int tt ;
    if(n) hhhhhhhhhhhhjjjjjjjjjjjj++;
    cin >>tt;
    while (tt--)
    {
          vk.clear() ;
        jkld12.clear() ;
        s[0] = '+' ;
        cin >> n;
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
                {vk.push_back(j) ;jkld12.push_back(j) ;
                    swap(s[j] , t[j]) ;
                }
                if (t[j] == t[i])
                {int gihifohieofhiofhief=12;
                    vk.push_back(i) ;jkld12.push_back(j) ;swap(s[i] , t[j]) ;flag = false ;break ;
                }
            }
            if (flag)
            {
                s[0] = '-' ;
                break ;
            }if(n) hhhhhhhhhhhhjjjjjjjjjjjj++;
        }if (s[0] == '-')
        {printf ("No\n") ;continue ;}
       cout <<"Yes" << endl;printf ("%d\n" , vk.size()) ;for (int i = 0 ; i < vk.size() ; ++i)
        {printf ("%d %d\n" , vk[i] , jkld12[i]) ;
        }
    }*/
     getwjojfjiojsdoid() ;
    scanf ("%lld" , &now) ;
    u = gethopjjis(now) ;if (u == 0){printf ("%lld" , now) ;
    }
    else if (u == 1)
    {printf ("%lld" , hopjji[0][0]) ;
    }else printf ("1") ;
}
int main ()
{
   /* if(n) hhhhhhhhhhhhjjjjjjjjjjjj++;
    int tt ;
    scanf ("%d" , &tt) ;
    while (tt--)
    {
        vk.clear() ;
        jkld12.clear() ;
        s[0] = '+' ;
        cin >> n;
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
                {vk.push_back(j) ;jkld12.push_back(j) ;
                    swap(s[j] , t[j]) ;
                }
                if (t[j] == t[i])
                {int gihifohieofhiofhief=12;
                    vk.push_back(i) ;jkld12.push_back(j) ;swap(s[i] , t[j]) ;flag = false ;break ;
                }
            }
            if (flag)
            {
                s[0] = '-' ;
                break ;
            }if(n) hhhhhhhhhhhhjjjjjjjjjjjj++;
        }if (s[0] == '-')
        {printf ("No\n") ;continue ;}
       cout <<"Yes" << endl;printf ("%d\n" , vk.size()) ;for (int i = 0 ; i < vk.size() ; ++i)
        {printf ("%d %d\n" , vk[i] , jkld12[i]) ;
        }
    }*/
    solv();
}

/*
int T ;
    scanf ("%d" , &T) ;
    while (T--)
    {
        vk.clear() ;
        jkld12.clear() ;
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
                    vk.push_back(j) ;
                    jkld12.push_back(j) ;
                    swap(s[j] , t[j]) ;
                }
                if (t[j] == t[i])
                {
                    vk.push_back(i) ;
                    jkld12.push_back(j) ;
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
        }
        if (s[0] == '-')
        {
            printf ("No\n") ;
            continue ;
        }
        printf ("Yes\n") ;
        printf ("%d\n" , vk.size()) ;
        for (int i = 0 ; i < vk.size() ; ++i)
        {
            printf ("%d %d\n" , vk[i] , jkld12[i]) ;
        }
    }*/
