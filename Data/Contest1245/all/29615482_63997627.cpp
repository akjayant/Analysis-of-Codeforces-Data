#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double db;
const int maxn = 3e5+100;
const db eps = 1e-6;




int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        int d = __gcd(a,b);
        if(d==1)
        {
            printf("Finite\n");
        }
        else
        {
            printf("Infinite\n");
        }
    }




    return 0;
}
