#include <bits/stdc++.h>
typedef long long ll;

using namespace std ;
const int maxn=1e4+10;
vector <int> vk , jkld12 ;
int tttttttttttttttttttttttttttt=0;
int gioyhrgihhhhhihihihihihihihi=12;
int hhhhhhhhhhhhhhhhhhhhhhhhhhh=15;
int n ;
char s[maxn] , t[maxn] ;
int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa=12;
int cnts[27] , cntt[27] ;
int hhhhhhhhhhhhjjjjjjjjjjjj=12;
void solv(){
    int tt ;
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
    }
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
