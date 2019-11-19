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

int main() {

    int t;
    sf(t)
    while(t--){

        ll n;
        sfl(n)

        ll i,j,k,l;
        ll ev=0,od=0;

        for(i=0;i<n;i++){
            sfl(j)
            if(j%2==0)
                ev++;
            else
                od++;
        }

        ll m;
        sfl(m)

        ll ans=0;
        for(i=0;i<m;i++){
            sfl(j)
            if(j%2==0){
                ans+=ev;
            }
            else{
                ans+=od;
            }
        }

        pfl(ans)

    }

    return 0;
}
