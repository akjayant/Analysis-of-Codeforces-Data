#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std ;

vector <int> V ;

int n ;
char s[10004] , t[10005] ;
int cnts[27] , cntt[27] ;
int main ()
{
    int T ;
    scanf ("%d" , &T) ;
    while (T--)
    {
        V.clear() ;
        scanf ("%d" , &n) ;
        scanf ("%s" , s + 1) ;
        scanf ("%s" , t + 1) ;
        for (int i = 1 ; i <= n ; ++i)
        {
            if (s[i] != t[i])
            {
                V.push_back(i) ;
            }
        }
        if (V.size() == 0)
        {
            printf ("Yes\n") ;
            continue ;
        }
        if (V.size() != 2)
        {
            printf ("No\n") ;
            continue ;
        }
        swap(s[V[0]] , t[V[1]]) ;
        if (s[V[0]] != t[V[0]] || s[V[1]] != t[V[1]])
        {
            printf ("No\n") ;
            continue ;
        }
        printf ("Yes\n") ;
    }
}
