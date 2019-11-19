/*
  user: sky48
  language: c++
  for dream for young
*/
#include<iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <map>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define N 200005
typedef long long ll;
using namespace std;
map <int,int> mp[N]; 
int lef,rig,u,nn,mm,n,upp,dwn,p[7],tim; 
struct node {
	int a,b; 
}f[7][N],s[N];
int gets()
{
	int v=0; char ch;bool f=0;
	while(!isdigit(ch=getchar())) if(ch=='-') f=1; v=ch-48;
	while( isdigit(ch=getchar())) v=(v<<1)+(v<<3)+ch-48;
	return f?-v:v;
}
bool cmp_upp(const node &x,const node &y){
	return x.a==y.a?x.b<y.b:x.a<y.a; }
bool cmp_rig(const node &x,const node &y){
	return x.b==y.b?x.a<y.a:x.b>y.b; }
bool cmp_dwn(const node &x,const node &y){
	return x.a==y.a?x.b>y.b:x.a>y.a; }
bool cmp_lef(const node &x,const node &y){
	return x.b==y.b?x.a>y.a:x.b<y.b; }

int main ()
{
//  freopen("tt.txt","r",stdin);
	nn=gets(); mm=gets(); n=gets(); 
	if(!n){ puts("Yes"); return 0;}
	rep(i,1,n){
		s[i].a=gets(), s[i].b=gets(); mp[s[i].a][s[i].b]=1; 
	}
	rep(i,1,n) rep(j,1,4) f[j][i]=s[i]; 
	sort(1+f[1],1+f[1]+n,cmp_upp);
	sort(1+f[2],1+f[2]+n,cmp_rig);
	sort(1+f[3],1+f[3]+n,cmp_dwn);
	sort(1+f[4],1+f[4]+n,cmp_lef);
	lef=upp=1, dwn=nn, rig=mm;
	p[1]=p[2]=p[3]=p[4]=1; u=1; 
	while(1){
		while((f[u][p[u]].b<lef || f[u][p[u]].b>rig || f[u][p[u]].a<upp ||f[u][p[u]].a>dwn) && p[u]<=n ) p[u]++; 
//		cout<<" wahile "<<u<<" ## "<<upp<<" "<<rig<<" "<<dwn<<" "<<lef<<" "<<p[u]<<endl; 
		if(p[u]==n+1){ puts("Yes"); return 0;}
		if(u==1){
			if(f[u][p[u]].a==upp){
				tim=f[u][p[u]].b-1; 
				//rep(i,lef,rig) if(!mp[upp][i]){ puts("No"); return 0;}
				rep(i,upp,dwn)rep(j,tim+1,rig)  if(!mp[i][j]){ puts("No"); return 0;}
				rig=tim; 
			}
			upp++; 
		}
		if(u==2){
			if(f[u][p[u]].b==rig){
				tim=f[u][p[u]].a-1; 
				//rep(i,upp,dwn) 
				rep(i,tim+1,dwn) rep(j,lef,rig) if(!mp[i][j]){ puts("No"); return 0;}
				dwn=tim;
			}
			rig--; 
		}
		if(u==3){
//			cout<<f[u][p[u]].a<<"   "<<dwn<<endl;
			if(f[u][p[u]].a==dwn){
				tim=f[u][p[u]].b+1; 
//				cout<<tim<<endl; 
				//rep(i,lef,rig) 
				rep(i,upp,dwn) rep(j,lef,tim-1) if(!mp[i][j]){ puts("No"); return 0;}
				lef=tim; 
			}
			dwn--; 
		}
		if(u==4){
			if(f[u][p[u]].b==lef){
				tim=f[u][p[u]].a+1; 
				//rep(i,upp,dwn) 
				rep(i,upp,tim-1)rep(j,lef,rig) if(!mp[i][j]){ puts("No"); return 0;}
				upp=tim; 
			}
			lef++; 
		}
		
		u=u%4+1; 
		
	}
	
	return 0;
}


/*

*/