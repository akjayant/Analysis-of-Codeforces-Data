#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5+100;

int main()
{
    int a,b,c,d,k;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c>>d>>k;
        c=(a+c-1)/c;
        d=(b+d-1)/d;
        k-=c+d;
        if(k<0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d %d\n",c,d);
        }
    }
    return 0;
}

/**
4
0 1 2 2
1 10 100 1000
*/
