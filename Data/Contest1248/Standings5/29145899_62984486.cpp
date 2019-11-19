#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
const int inf=1e9+7;
void read(ll &x){
    ll f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
ll t,n,m,p[maxn],q[maxn];
int main(){
		read(n);
		ll i,c1=0,c2=0;
		for(i=1;i<=n;i++)read(p[i]);
		sort(p+1,p+1+n);
		for(i=1;i<=n/2;i++)c1+=p[i];
		for(i=n/2+1;i<=n;i++)c2+=p[i];
		cout<<c1*c1+c2*c2;		
    return 0;
}