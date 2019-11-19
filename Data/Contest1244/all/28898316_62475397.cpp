#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define LL long long 
typedef long long ll;
const int N=5e5+5;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef pair<int,int> pii;
ll n,p,w,d;
inline ll gcd(ll x,ll y){
	return !y?x:gcd(y,x%y);
}

/*LL e_gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    LL ans=e_gcd(b,a%b,x,y);
    LL tmp=x;
    x=y;
    y=tmp-a/b*y;
    return ans;
}
void cal(LL a,LL b,LL c)
{
    LL x,y;
    LL gcd=e_gcd(a,b,x,y);
    if(c%gcd!=0) {
    	puts("-1");
    	return;	
    }
    x*=c/gcd;b/=gcd;
    if(b<0) b=-b;
    LL ans=x%b;
    if(ans<0) ans+=b;
   	LL t=(p-ans*d)/w;
   	if(t<0||t*w+ans*d!=p||t+ans>n) puts("-1");
   	else cout<<t<<' '<<ans<<' '<<n-ans-t;
}*/
int main(){
	cin>>n>>p>>w>>d;
	ll x=p/w,y=0;
	for(;x>=(p/w)-d-100000&&x>=0;x--){
		if((p-w*x)%d==0) {
			y=(p-w*x)/d;
			if(x+y>n) {puts("-1");return 0;}
			cout<<x<<' '<<y<<' '<<n-x-y;
			return 0;
		}
	}
	puts("-1");
	return 0;
} 