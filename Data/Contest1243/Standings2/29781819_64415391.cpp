#include<bits/stdc++.h>
typedef int LL;
const LL maxn=1e6+9;
LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){ if(c=='-') f=-1; c=getchar(); }
	while(c>='0' && c<='9'){ x=(x<<3)+(x<<1)+c-'0'; c=getchar(); } return x*f;
}
LL T,n,m;
struct node{
	LL to,nxt;
}dis[maxn];
LL num;
LL head[maxn];
std::set<LL> Set,Set1;
std::set<LL>::iterator it1,it2;
LL fa[maxn],size[maxn],del[maxn];
void Add(LL u,LL v){
	dis[++num]=(node){v,head[u]}; head[u]=num;
}
LL Find(LL x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
int main(){
	n=Read(); m=Read();
	for(LL i=1;i<=m;++i){
		LL u(Read()),v(Read());
		Add(u,v); Add(v,u);
	}
//	Set.insert(1);
	for(LL i=1;i<=n;++i) Set.insert(i),fa[i]=i,size[i]=1;
	LL ans(0);
	for(LL i=1;i<=n;++i){
		for(LL j=head[i];j;j=dis[j].nxt){
			LL v(dis[j].to),x(Find(v));
			++del[x];
			if(del[x]==size[x]) Set1.insert(x),Set.erase(x);
		}
		for(LL j=head[i];j;j=dis[j].nxt){
			LL v(dis[j].to),x(Find(v));
			--del[x];
		}
		if(!Set.empty()){
			it2=Set.find(Find(i));
			for(it1=Set.begin();it1!=Set.end();++it1){
				if(*it1==*it2) continue;
				size[*it2]+=size[*it1]; fa[*it1]=*it2;
			}
			Set.clear(); Set.insert(*it2);
		}
		for(it1=Set1.begin();it1!=Set1.end();++it1)
			Set.insert(*it1);
		Set1.clear();
	}
	printf("%d\n",Set.size()-1);
	return 0;
}