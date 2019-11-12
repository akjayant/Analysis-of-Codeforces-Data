#include<bits/stdc++.h>
using namespace std;
int n,a,b;
#define mod 1000000007
long long get(long long x,long long p){
    long long ans=1,tmp=x;
    while(p){
        if(p&1)ans=tmp*ans%mod;
        tmp=tmp*tmp%mod;
        p>>=1;
    }
    return ans;
}
void work(){
    scanf("%d%d",&a,&b);
   // printf("%lld\n",get(2,b));
    printf("%lld\n",((get(get(2,b)-1,a)+mod)%mod));
}
int main(){
    int t=1;//scanf("%d",&t);
    while(t--)work();
    return 0;
}
