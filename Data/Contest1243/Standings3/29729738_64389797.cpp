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
