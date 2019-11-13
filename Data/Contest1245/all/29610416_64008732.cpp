#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define MAXN 10005
char str[MAXN],ans[MAXN];
int main(){
	int t,n,a[2],b[2],c[2];
	cin>>t;
	while(t--){
		a[1]=b[1]=c[1]=0;
		cin>>n>>a[0]>>b[0]>>c[0]>>str;
		for(int i=0;i<n;i++){
			if(str[i]=='R')	a[1]++;
			if(str[i]=='P')	b[1]++;
			if(str[i]=='S')	c[1]++;
		}
		int win=min(a[0],c[1])+min(b[0],a[1])+min(c[0],b[1]);
		if(win*2<n){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
			int r=min(a[0],c[1]),p=min(b[0],a[1]),s=min(c[0],b[1]);
			memset(ans,0,sizeof(ans));
			for(int i=0;i<n;i++){
				if(str[i]=='S'){
					if(r>0)	--r,--a[0],ans[i]='R';
				}
				if(str[i]=='R'){
					if(p>0)	--p,--b[0],ans[i]='P';
				}
				if(str[i]=='P'){
					if(s>0)	--s,--c[0],ans[i]='S';
				}
			}
			for(int i=0;i<n;i++)
				if(!ans[i]){
					if(a[0])	--a[0],ans[i]='R';
					else if(b[0])	--b[0],ans[i]='P';
					else if(c[0])	--c[0],ans[i]='S';
				}
			cout<<ans<<endl;
		}
	}
	return 0;
}
