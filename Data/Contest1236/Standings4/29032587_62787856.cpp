#include<bits/stdc++.h>
using namespace std;
#define MAX 300001
#define MAX_POINTS 201
#define DEFAULT 1;
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

int main()
{
    int t,k;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int stones=0;
        if(c>=2&&b>=1)
        {
            if(b*2<=c)
            {
                int s=3*b;
                stones+=s;
                b=0;
                c=c-2*b;
            }
            else
            {
                int s=c/2;
                stones=stones+3*s;
                b=b-s;
                c=c-2*s;
            }
        }
        if(a>=1&&b>=2)
        {
            if(a*2<=b)
            {
                int s=3*a;
                stones+=s;
                a=0;
                a=b-2*a;
            }
            else
            {
                int s=b/2;
                stones=stones+3*s;
                a=a-s;
                b=b-2*s;
            }
        }
        printf("%d\n",stones);
    }
    return 0;
}
