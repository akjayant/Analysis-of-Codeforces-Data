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
	read(t);
	while(t--){
		read(n);
		int i,j;
		for(i=1;i<=n;i++)read(p[i]);
		read(m);
		for(i=1;i<=m;i++)read(q[i]);
		ll c1=0,c2=0,c3=0,c4=0;
		for(i=1;i<=n;i++){
			if(p[i]%2==0)c1++;
			else c2++;
		}
		for(i=1;i<=m;i++){
			if(q[i]%2==0)c3++;
			else c4++;
		}
		cout<<c1*c3+c2*c4<<endl;
	}
	
    return 0;
}