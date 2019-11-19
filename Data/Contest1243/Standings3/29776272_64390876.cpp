#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll s[1000010];

int main()
{
    ll i, j, n, k, r, last=1;

    for(i=2; i<=1000; i++)
    {
        if(s[i]==0)
        {
            for(j=i*i; j<=1000000; j+=i) s[j]=1;
        }
    }

    scanf("%lld", &n);
    ll cm=n;
    r=sqrt(n);
    ll cnt=0;
    for(i=2; i<=r; i++)
    {
        if(s[i]==1) continue;
        if(n%i==0) cnt++, last=i;
        while((n%i)==0) n=n/i;
    }
    //cout<<n<<endl;
    if(n!=1) cnt++, last=n;

    if(cnt==1) printf("%lld\n", last);
    else printf("1\n");


    return 0;
}
