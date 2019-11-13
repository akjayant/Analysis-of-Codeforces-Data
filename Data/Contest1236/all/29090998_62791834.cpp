#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define mod 1000000007ll
using namespace std;
long long n,m;
long long read(){
char c=getchar();long long ans=0;
while (c<'0'||c>'9') c=getchar();
while (c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
return ans;
}
long long power(long long x,long long y){
long long ans=1,now=x%mod;
for (register long long i=y;i;i>>=1,now=now*now%mod)
if (i&1) ans=ans*now%mod;
return ans;
}
int main(){
n=read(),m=read();
printf("%I64d",power(power(2,m)+mod-1,n));
return 0;
}
