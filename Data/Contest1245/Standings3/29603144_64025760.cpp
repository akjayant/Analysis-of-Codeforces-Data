#include<bits/stdc++.h>
#define LL long long
#define MAXN 2005
using namespace std;

int N,M;
struct Node{
	LL x,y,c,k;
} n[MAXN]; 

bool vis[MAXN];

int p[MAXN], id[MAXN];
int findR(int x){
	if(x==p[x]) return x;
	else return p[x] = findR(p[x]);
}


LL dis(int i, int j){
	return (abs(n[i].x - n[j].x) + abs(n[i].y - n[j].y)) * (n[i].k + n[j].k);
}

struct edge{
	int u,v;
	LL w;
	
	edge(int u=0, int v=0, LL w=0):u(u), v(v), w(w){}
	
	bool operator < (const edge& e1) const{
		return w < e1.w;
	}
} e[MAXN*MAXN];

int e0[MAXN], e1[MAXN], top = 0;

int main(){
	
	ios::sync_with_stdio(0);
	
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>n[i].x>>n[i].y;
	}
	for(int i=1;i<=N;i++) cin>>n[i].c;
	for(int i=1;i<=N;i++) cin>>n[i].k;
	
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			e[++M] = edge(i,j,dis(i,j));
		}
	}
	
	
	//
	sort(e+1, e+1+M);
	
	for(int i=1;i<=N;i++){
		p[i] = id[i] = i;
	}
	
	LL ans = 0;
	int u,v,ru,rv;
	LL w;
	for(int i=1;i<=M;i++){
		u = e[i].u; v = e[i].v; w = e[i].w;
		ru = findR(u); rv = findR(v);
		
//		//cout<<u<<" "<<v<<" "<<ru<<" "<<rv<<" "<<w<<" "<<ans<<endl;
//		for(int i=1;i<=N;i++){
//			cout<<i<<" "<<p[i]<<" "<<id[i]<<endl;
//		}
//		cout<<"? "<<max(n[id[ru]].c, n[id[rv]].c)<<endl;
		if(ru==rv) continue;
		
		if(w < max(n[id[ru]].c, n[id[rv]].c)){
			e0[top+1] = u;
			e1[top+1] = v;
			++top;
			ans += w;
			
			if(n[id[ru]].c < n[id[rv]].c) id[rv] = id[ru];
			p[ru] = rv;
		}
	}
	
	for(int i=1;i<=N;i++){
		ru = findR(i);
		if(vis[id[ru]]) continue;
		vis[id[ru]] = 1;
		ans += n[id[ru]].c;
	}
	
	cout<<ans<<endl;
	cout<<N - top<<endl;
	for(int i=1;i<=N;i++){
		if(vis[i]) cout<<i<<" ";
	}
	cout<<endl;
	
	cout<<top<<endl;
	for(int i=1;i<=top;i++){
		cout<<e0[i]<<" "<<e1[i]<<endl;
	}	
	return 0;
}