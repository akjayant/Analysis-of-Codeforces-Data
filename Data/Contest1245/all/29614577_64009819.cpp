#include<bits/stdc++.h>
using namespace std;

int vis[109];
char s[109],res[109];

int main()
{
	ios::sync_with_stdio(false);
	int _;cin>>_;
	while(_--){
		int n,a,b,c,ans=0;
		cin>>n>>a>>b>>c;
		cin>>(s+1);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++){
			if(s[i]=='R'){
				if(b){
					vis[i]=1;
					res[i]='P';
					ans++;
					b--;
				}
			} else if(s[i]=='P'){
				if(c){
					vis[i]=1;
					res[i]='S';
					ans++;
					c--;
				}
			} else if(s[i]=='S'){
				if(a){
					vis[i]=1;
					res[i]='R';
					ans++;
					a--;
				}
			}
		}
		if(ans>=ceil(1.0*n/2.0)){
			cout<<"YES"<<'\n';
			for(int i=1;i<=n;i++){
				if(vis[i]){
					cout<<res[i];
				} else {
					if(a){
						cout<<"R";
						a--;
					} else if(b){
						cout<<"P";
						b--;
					} else {
						cout<<"S";
						c--;
					}
				}
			}
			cout<<'\n';
		} else{
			cout<<"NO"<<'\n';
		} 
	}
	return 0;
}