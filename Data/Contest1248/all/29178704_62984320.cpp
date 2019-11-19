#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define ll long long
#define sf(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define sfc(a) scanf("%c",&a);
#define pf(a) printf("%d\n",a);
#define pfl(a) printf("%lld\n",a);
#define pb push_back
#define ft first
#define sd second
typedef pair<ll, ll> PII;
#define MAXN 100001

ll a[MAXN];

int main() {

    ll n;
    sfl(n)

    ll i,j,k=0,l=0;

    for(i=0;i<n;i++)
        sfl(a[i])

    sort(a,a+n);

    for(i=0,j=n-1;i<n/2;i++,j--){
        k+=a[i];
        l+=a[j];
    }

    ll ans=0;
    if(n%2){
        ans=max(((k+a[n/2])*(k+a[n/2]))+(l*l),(k*k)+((l+a[n/2])*(l+a[n/2])));
        pfl(ans)
    }
    else{
        ans=(k*k)+(l*l);
        pfl(ans)
    }

    return 0;
}
