#include<bits/stdc++.h>
using namespace std;

const int N=510;


char ch[N];
int a[N];
int f[N],g[N];

int main() {
	int n;
	cin>>n;
	scanf("%s",ch+1);
	int Ans=0,ii=1,jj=1;
	for(int k=1;k<=n;k++) 
		for(int j=1;j<=n;j++) {
			swap(ch[k],ch[j]);	
			memset(a,0,sizeof a);
			memset(f,0,sizeof f);
			memset(g,0,sizeof g);
			int S=0;
			for(int i=1;i<=n;i++) 
				if(ch[i]=='(') a[i]=a[i-1]+1;else a[i]=a[i-1]-1;
			if(a[n]!=0) {
				swap(ch[k],ch[j]);
				continue;
			}
			f[1]=a[1];
			for(int i=2;i<=n;i++) f[i]=min(f[i-1],a[i]);
			g[n]=a[n];
			for(int i=n-1;i;i--) g[i]=min(g[i+1],a[i]);
			for(int i=1;i<=n;i++) {
				if(g[i]-a[i-1]<0) continue;
				if(f[i-1]+a[n]-a[i-1]<0) continue;
				S++;
			}
			if(S>Ans) ii=k,jj=j,Ans=S;
			swap(ch[k],ch[j]);
		}
	cout<<Ans<<endl;
	cout<<ii<<' '<<jj<<endl;
}
				
			
				
	