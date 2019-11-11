#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int MAXN = 105;
const int INF = 0X3f3f3f3f;
const int MOD = 1e9+7;
const int N=2,M=2;
char ans[MAXN];
int s,t,h[2];
int head[N],nex[M],to[M],w[M],tot=1;
inline void ade(int a,int b,int c){
	to[++tot]=b; w[tot]=c; nex[tot]=head[a]; head[a]=tot;
}
inline void add(int a,int b,int c){
	ade(a,b,c);	ade(b,a,0);
}
inline int bfs(){
	queue<int> q;	q.push(s); memset(h,0,sizeof h); h[s]=1;
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
	while(bfs())	res+=dfs(s,INF);
	return res;
}
int main(){
    int T; cin>>T;
    while(T--){
        int n,a,b,c; cin>>n>>a>>b>>c;
        string ss;
        cin>>ss;
        memset(ans,0,sizeof(ans));
        int R=0,S=0,P=0,cnt=0;
        int up = (n+1)/2;
        for(int i=0;i<n;i++){
            if(ss[i]=='R'){
                if(b)
                    ans[i] = 'P',cnt++,b--;
            }
            if(ss[i]=='P'){
                if(c)
                    ans[i] = 'S',cnt++,c--;
            }
            if(ss[i]=='S'){
                if(a)
                    ans[i] = 'R',cnt++,a--;
            }
        }
        if(cnt>=up){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
                if(ans[i]=='P' || ans[i]=='R' || ans[i]=='S') cout<<ans[i];
                else {
                    if(a) cout<<'R',a--;
                    else if(b) cout<<'P',b--;
                    else if(c) cout<<'S',c--;
                }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

