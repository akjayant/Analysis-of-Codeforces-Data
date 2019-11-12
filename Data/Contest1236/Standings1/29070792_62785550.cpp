#include<bits/stdc++.h>
#define ll long long
#define scan(x) scanf("%d",&x)
#define scanl(x) scanf("%I64d",&x)
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+5;
const int mod=1e9+7; 
int n;
int t,a,b,c;

int main(){
//	freopen("in.txt","r",stdin);
	scan(t);
	For(i,1,t){
		scan(a);scan(b);scan(c);
		int ans=0;
		while(c>=2&&b>=1){
			ans+=3;
			c-=2;b-=1;
		}
		while(b>=2&&a>=1){
			ans+=3;
			b-=2;a-=1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}