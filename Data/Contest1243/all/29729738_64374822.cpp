#include <stdio.h>

int n ;
int num[1005] ;

bool check(int x)
{
    int cnt = 0 ;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (num[i] >= x)
            ++cnt ;
    }
    if (cnt >= x)
        return true ;
    return false ;
}

int main ()
{
    int T ;
    scanf ("%d" ,&T) ;
    while (T--)
    {
        scanf ("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i)
        {
            scanf ("%d" , &num[i]) ;
        }
        int res ;
        int l = 0 , r = 1000 ;
        while (l <= r)
        {
            int mid = (l + r) >> 1 ;
            if (check (mid))
            {
                res = mid ;
                l = mid + 1 ;
            }
            else
            {
                r = mid - 1 ;
            }
        }
        printf ("%d\n" , res) ;
    }
}
