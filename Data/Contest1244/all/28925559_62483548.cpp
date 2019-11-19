#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,C[3][N],To[N],HEAD[N],Ne[N*2],E[N*2],b;
int s,e,lian,rt,AN[3],K[N];
long long Sum[5][5],ans,_1,_2,_3,_4,_5,_6;
void ADD(int s,int e) {
	Ne[++b]=HEAD[s],HEAD[s]=b,E[b]=e;
}
void DFS(int i,int f,int k) {
	k==3?k-=3:k;
	K[i]=k;
	Sum[k][0]+=C[0][i];
	Sum[k][1]+=C[1][i];
	Sum[k][2]+=C[2][i];
	for(int z=HEAD[i]; z; z=Ne[z])
		if(E[z]!=f) DFS(E[z],i,k+1);
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)scanf("%d",&C[0][i]);
	for(int i=1; i<=n; ++i)scanf("%d",&C[1][i]);
	for(int i=1; i<=n; ++i)scanf("%d",&C[2][i]);
	for(int i=1; i<n; ++i) {
		scanf("%d %d",&s,&e);
		ADD(s,e),ADD(e,s);
		To[s]++,To[e]++;
	}
	lian=1;
	for(int i=1; i<=n; ++i) {
		lian&=To[i]<=2;
		if(To[i]==1)rt=i;
	}
	if(!lian)return puts("-1"),0;
	DFS(rt,0,0),ans=1e18;
	_1=Sum[0][0]+Sum[1][1]+Sum[2][2];
	_2=Sum[0][0]+Sum[1][2]+Sum[2][1];
	_3=Sum[0][1]+Sum[1][0]+Sum[2][2];
	_4=Sum[0][1]+Sum[1][2]+Sum[2][0];
	_5=Sum[0][2]+Sum[1][0]+Sum[2][1];
	_6=Sum[0][2]+Sum[1][1]+Sum[2][0];
	ans=min(_1,min(_2,min(_3,min(_4,min(_5,_6)))));
	printf("%lld\n",ans);
	if(ans==_1) AN[0]=1,AN[1]=2,AN[2]=3;
	else if(ans==_2)AN[0]=1,AN[1]=3,AN[2]=2;
	else if(ans==_3)AN[0]=2,AN[1]=1,AN[2]=3;
	else if(ans==_4)AN[0]=2,AN[1]=3,AN[2]=1;
	else if(ans==_5)AN[0]=3,AN[1]=1,AN[2]=2;
	else if(ans==_6)AN[0]=3,AN[1]=2,AN[2]=1;
	for(int i=1; i<=n; ++i) printf("%d ",AN[K[i]]);
	return 0;
}
