#include <bits/stdc++.h>
#define ll long long;

using namespace std;
long long t,n,x;
long long a1=0,a2=0;
long long b1=0,b2=0;
int main() {
    scanf("%lld",&t);
    while(t--)
    {
        a1=0;
        a2=0;
        b1=0;
        b2=0;
        scanf("%lld",&n);
        while(n--)
        {
            scanf("%lld",&x);
            if(x%2)
            {
                a1++;
            } else
            {
                a2++;
            }
        }
        scanf("%lld",&n);
        while(n--)
        {
            scanf("%lld",&x);
            if(x%2)
            {
                b1++;
            } else
            {
                b2++;
            }
        }
        printf("%lld\n",a1*b1+a2*b2);
    }
    return 0;
}