#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main() {
#ifdef Yinku
    freopen("Yinku.in", "r", stdin);
#endif // Yinku
    while(~scanf("%lld",&n)){
        ll cn=n;
        vector<ll> fac;
        for(ll i=2;i*i<=n;++i){
            if(n%i==0){
                fac.push_back(i);
                while(n%i==0)
                    n/=i;
            }
        }
        if(n!=1)
            fac.push_back(n);
        if(fac.size()>=2||cn==1){
            printf("1\n");
        }
        else{
            printf("%lld\n",fac[0]);
        }
    }
}
