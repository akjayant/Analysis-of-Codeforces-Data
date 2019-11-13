#include <bits/stdc++.h> 
#define N 110
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll read(){
	char c=getchar();bool flag=0;ll x=0;
	while(c<'0'||c>'9'){if(c=='-')flag=1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return flag?-x:x;
}
char s0[N],q[N];
int main(){
	ll T=read();
	while(T--){
		memset(q,0,sizeof(q));
		ll n=read();
		ll r=read(),p=read(),s=read(),ans=0;
		scanf("%s",s0+1); 
		for(ll i=1;i<=n;i++){
			if(s0[i]=='R'&&p){
				p--;
				q[i]='P';
				ans++;
			}
			if(s0[i]=='P'&&s){
				s--;
				q[i]='S';
				ans++;
			}
			if(s0[i]=='S'&&r){
				r--;
				q[i]='R';
				ans++;
			}
		}
		if(ans>=(n+1)/2) printf("YES\n");
		else{
			printf("NO\n");
			continue;
		}
		for(ll i=1;i<=n;i++){
			if(q[i]) cout<<q[i];
			else{
				if(r){
					r--;
					cout<<'R';
				}
				else{
					if(s){
						s--;
						cout<<'S';
					}
					else{
						p--;
						cout<<'P';
					}
				}
			}
		}
		printf("\n");
	} 
}
