#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define debug(x) cout<<#x<<" is "<<x<<endl;

const int maxn=1e5+5;
const ll mod=1e9+7;

char ch[2][maxn];
int in[2][30],a[maxn*2];

int main(){
    ll n;
    scanf("%lld",&n);
   // if(n%2==0)printf("2\n");
   // else{
        int t=0;
        ll N=n;
        ll ac=0;
        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                while(n%i==0)n/=i;
                t++;
            }
            ac=i;
        }
        if(n>1){t++;ac=n;}
        if(t==1)printf("%lld\n",ac);
        else if(t>1)printf("1\n");
        else printf("%lld\n",N);
   // }
    return 0;

}
