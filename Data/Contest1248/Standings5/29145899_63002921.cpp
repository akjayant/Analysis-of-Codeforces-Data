#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+10;
const ll mod=1e9+7;
void read(ll &x){
    ll f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
ll n,m,a[maxn],b[maxn];



int main(){
	read(n);
	read(m);
	ll i,j;
	a[1]=2;a[2]=4;
	for(i=3;i<=n;i++){
		a[i]=a[i-1]+a[i-2];
		a[i]%=mod;
	}
	//cout<<a[n]<<endl;
	b[1]=a[n];b[2]=b[1]+2;
	for(i=3;i<=m;i++){
		b[i]=b[i-1]+b[i-2]-(b[1]-2)+mod;
		b[i]%=mod;
	}
	cout<<b[m];		
    return 0;
}