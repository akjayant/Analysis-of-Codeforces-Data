#include <bits/stdc++.h>
#include <algorithm>
#define pi 3.14159265358
using namespace std;
typedef long long ll;
const ll mod=1000000007;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int maxn = 3e6 + 5;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
ll gcd(ll x, ll y){
     if(y==0)
	 	return x;    
     if(x<y)
	 	return gcd(y,x);    
     else
	 	return gcd(y,x%y); 
} 
bool vis[100100];
int main(){
	ll n,p,d,w;
	scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
	ll temp=gcd(w,d);
	temp=gcd(temp,p);
	w/=temp;
	p/=temp;
	d/=temp;
	temp=p%w;
	for(ll i=0;;i++){
		if((i%w*d)%w==p%w){
//			cout<<"123";
			ll b=i;
			ll a=(p-i*d)/w;
			ll c=n-a-b;
//			cout<<a<<" "<<b<<" "<<c<<endl;
			if(a>=0&&a<=n&&b>=0&&b<=n&&c>=0&&c<=n){
				printf("%lld %lld %lld\n",a,b,c);
				return 0;
			}
			else{
				printf("-1\n");
				return 0;
			}
		}
		else if(vis[(i%w*d)%w]==0){
			vis[(i%w*d)%w]=1;
		}
		else if(vis[(i%w*d)%w]==1){
			printf("-1\n");
			return 0;
		}
	}
}