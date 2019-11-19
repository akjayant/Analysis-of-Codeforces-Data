#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline long long read(){
	long long num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
	return num*neg;
}

struct node{
	ll from,to,val;
}s[5000010];

inline bool cmp1(node a,node b){return a.val<b.val;}

int cnt;
ll fa[2010],x[2010],y[2010],c[2010],k[2010],tot,p,q,ans,res,line[5000010],tower[2010];
ll all,n;
inline void insert(ll x,ll y,ll z){s[++cnt].from=x,s[cnt].to=y,s[cnt].val=z;}

inline ll find(ll x){return fa[x]==x?x:fa[x]=find(fa[x]);}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)fa[i]=i,x[i]=read(),y[i]=read();
	for(int i=1;i<=n;i++)c[i]=read(),insert(0,i,c[i]);
	for(int i=1;i<=n;i++)k[i]=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++)
		insert(i,j,(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]));
	sort(s+1,s+cnt+1,cmp1);
	tot=0;
	for(int i=1;tot<n&&i<=cnt;i++)
	{
		p=find(s[i].from),q=find(s[i].to);
		if(p!=q){
			ans+=s[i].val;tot++;fa[p]=q;
			if(s[i].from==0)tower[++all]=s[i].to;
			else if(s[i].to==0)tower[++all]=s[i].from;
			else line[++res]=i;
		}
	}
	cout<<ans<<endl<<all<<endl;
	sort(tower+1,tower+all+1);
	for(int i=1;i<=all;i++)cout<<tower[i]<<" ";cout<<endl<<res<<endl;
	for(int i=1;i<=res;i++)cout<<s[line[i]].from<<" "<<s[line[i]].to<<endl;
	return 0;
}