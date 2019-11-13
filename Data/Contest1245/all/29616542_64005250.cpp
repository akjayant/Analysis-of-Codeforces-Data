#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define ll long long
#define ull unsigned long long
#define sscc ios::sync_with_stdio(false);cin.tie(0);
#define ms(a) memset(a,0,sizeof(a))
#define mss(a) memset(a,-1,sizeof(a))
#define msi(a) memset(a,inf,sizeof(a))
using namespace std;

char a[]={' ','R','P','S'};
char vis[1005];

int main()
{
	sscc;
	ll t;
	cin>>t;
	while(t--){
		ll n,a,b,c;
		cin>>n>>a>>b>>c;
		ll a1=a,b1=b,c1=c;
		string s;
		cin>>s;
		ms(vis);
		//R石头 P布 S剪刀
		int ans=0; 
		for(int i=0;i<n;i++){
			if(s[i]=='R'){
				if(b)	b--,ans++,vis[i]='P';		
			}else if(s[i]=='P'){
				if(c)	c--,ans++,vis[i]='S';
			}else{
				if(a)	a--,ans++,vis[i]='R';
			}
		}
		for(int i=0;i<n;i++){
			if(!vis[i]){
				if(a){
					vis[i]='R';	
					a--;
				}else if(b){
					vis[i]='P';
					b--;
				}else{
					vis[i]='S';
					c--;
				}
			}
		}
		if(ans>=(n+1)/2){
			puts("YES");
			for(int i=0;i<n;i++){
				printf("%c",vis[i]);
			}
			puts("");
		}else{
			puts("NO");
		}
	}
	return 0;
}

