#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,n0;
vector<pair<ll,ll>>primes;
int main()
{
    scanf("%lld",&n);
    n0=n;
    if(n==1){
        printf("1\n");
        return 0;
    }
    for(ll i=2;i*i<=n;i++){
        int cnt=0;
        //printf("n:%lld i:%lld n mod i:%lld\n",n,i,n%i);
        while(n%i==0){
            cnt++;
            n/=i;
        }
        if(cnt){
            primes.push_back({i,cnt});
        }
    }
    if(n!=1){
        primes.push_back({n,1});
    }
    if(primes.size()>1){
        printf("1\n");
    }
    else{
        printf("%lld\n",primes[0].first);
    }
    return 0;
}
