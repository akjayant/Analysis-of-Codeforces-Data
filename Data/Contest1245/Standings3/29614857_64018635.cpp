#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int MAXN = 1e5+50;
const int INF = 0X3f3f3f3f;
const int MOD = 1e9+7;
const int N=1,M=1;
char s[MAXN];
LL a[MAXN];
int h[1],t;
int head[N],nex[M],to[M],w[M],tot=1;
inline void ade(int a,int b,int c){
	to[++tot]=b; w[tot]=c; nex[tot]=head[a]; head[a]=tot;
}
inline void add(int a,int b,int c){
	ade(a,b,c);	ade(b,a,0);
}
inline int bfs(){
	queue<int> q;	q.push(0); memset(h,0,sizeof h); h[0]=1;
	while(q.size()){
		int u=q.front();	q.pop();
		for(int i=head[u];i;i=nex[i]){
			if(!h[to[i]]&&w[i]){
				h[to[i]]=h[u]+1;	q.push(to[i]);
			}
		}
	}
	return h[t];
}
int dfs(int x,int f){
	if(x==t)	return f; int fl=0;
	for(int i=head[x];i&&f;i=nex[i]){
		if(h[to[i]]==h[x]+1&&w[i]){
			int mi=dfs(to[i],min(w[i],f));
			w[i]-=mi; w[i^1]+=mi; fl+=mi; f-=mi;
		}
	}
	if(!fl)	h[x]=-1;
	return fl;
}
int dinic(){
	int res=0;
	while(bfs())	res+=dfs(0,1);
	return res;
}
int main(){
    cin>>s;
    int len = strlen(s);
    LL res = 1;
    a[1] = a[0] = 1;
    for(int i=2;i<=len;i++) a[i] = (a[i-1]+a[i-2])%MOD;
    for(int i=0;i<len;i++){
        if(s[i]=='m' || s[i]=='w') { cout<<0<<endl;return 0; }
        if(s[i]=='u'){
            int cnt = 0,k = i;
            while(s[k]=='u')
                cnt++,k++;
            if(cnt>=2)
                res = (a[cnt]*res%MOD)%MOD;
            i = k-1;
        }
        else if(s[i]=='n'){
            int cnt = 0,k = i;
            while(s[k]=='n')
                cnt++,k++;
            if(cnt>=2)
                res = (a[cnt]*res%MOD)%MOD;
            i = k-1;
        }
    }
    cout<<res<<endl;
    return 0;
}

