#include<bits/stdc++.h>
using namespace std;const int N=1e6+7;typedef long long ll;
ll n,j;int i,cnt;
int main(){
    cin>>n;
    for(i=2;1LL*i*i<=n;++i)if(n%i==0){
        j=i;while(n%i==0)n/=i;++cnt;
    }
    if(n!=1){
        ++cnt;j=n;
    }
    if(cnt==0||cnt>=2)puts("1");else printf("%lld\n",j);
}
