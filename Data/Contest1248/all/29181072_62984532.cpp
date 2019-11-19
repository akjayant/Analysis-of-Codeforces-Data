
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll nn,nm,ans=0;
       scanf("%lld",&nn);
        ll a=0,a1=0,b=0,b1=0;
        for(ll i=1;i<=nn;i++)
        {
            ll k;
            cin>>k;
            if(k%2==0)a++;
            else a1++;
        }
        for(int i=0;i<10;i++)
        {
            int s;
            s++;
        }
        scanf("%lld",&nm);
        for(ll i=1;i<=nm;i++)
        {
            ll k;
            scanf("%lld",&k);
            if(k%2==0)b++;
            else b1++;
        }
        for(int i=0;i<10;i++)
        {
            int s;
            s++;
        }
        for(int i=0;i<10;i++)
        {
            int s;
            s++;
        }
        ans=(a*b)+(a1*b1);
      printf("%lld\n",ans);
    }
    return 0;
}
/*
3
3
1 3 2
2
0 3
1
1
1
1
1
2
1
1
*/
