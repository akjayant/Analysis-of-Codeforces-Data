#include <bits/stdc++.h>
using namespace std;
#define ll long long

char s[10010], t[10010];


int main()
{
    ll k, n, m, i, cnt;

    scanf("%lld", &k);

    while(k--)
    {
        scanf("%lld", &n);
        scanf(" %s %s", s, t);
        char a, b;
        ll val=1;
        for(i=0; i<n; i++)
        {
            if(s[i]!=t[i])
            {
                a=s[i];
                b=t[i];
                val=0;
                i++;
                break;
            }
        }
        for( ; i<n; i++)
        {
            if(s[i]!=t[i])
            {
                if(s[i]==a && t[i]==b) val=1;
                else val=0;
                i++;
                break;
            }
        }
        for(; i<n; i++)
        {
            if(s[i]!=t[i])
            {
                val=0;
                break;
            }
        }
        if(val==0) printf("No\n");
        else printf("Yes\n");

    }


    return 0;
}
