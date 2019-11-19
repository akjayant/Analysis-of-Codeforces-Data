#include<bits/stdc++.h>
#define bclz(x) (__builtin_clz(x))
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int,int> pii;

#define NN 400010
char s[NN];
char ss[NN];
int f[NN];
int vst[NN];
int n;
int fg(int x){
	int vv=x%n+n;
	if(vv>n) vv-=n;
	return vv;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	s[0]=s[n];
	s[n+1]=s[1];
	for(int i=n+1;i<=2*n;i++) s[i]=s[i-n];
	for(int i=0;i<=2*n;i++) ss[i]=s[i];
	int ff=0,gg=0;
	for(int i=1;i<=n;i++){
		if(s[i]!=s[i-1]&&s[i]!=s[i+1]) ff=1;
		else gg=1;
	}
	if(!ff){
		for(int i=1;i<=n;i++) printf("%c",s[i]);
		return 0;
	}
	if(!gg){
		if(k&1){
			for(int i=1;i<=n;i++){
				if(s[i]=='B') putchar('W');
				else putchar('B');
			}
		}
		else{
			for(int i=1;i<=n;i++) printf("%c",s[i]);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]==s[i-1]||s[i]==s[i+1]) continue;
		f[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(vst[i]||f[i]==0) continue;
		int st=i;
		int L=i,R=i,tmp;
		while(s[fg(st)]!=s[fg(st-1)]&&s[fg(st)]!=s[fg(st+1)]){
			st=fg(st+1);
			R++;
		}
		R--;
		st=i;
		while(s[fg(st)]!=s[fg(st-1)]&&s[fg(st)]!=s[fg(st+1)]){
			st=fg(st-1);
			L--;
		}
		L++;
		for(int j=L;j<=R;j++) vst[fg(j)]=1;
		tmp=fg(L-1);
		for(int j=L;j<=min(L+((R-L)/2),L+k-1);j++){
			int jj=fg(j);
			ss[jj]=s[tmp];
		}
		tmp=fg(R+1);
		for(int j=R;j>=max(R-((R-L)/2),R-k+1);j--){
			int jj=fg(j);
			ss[jj]=s[tmp];
		}
		for(int j=L+k;j<=R-k;j++){
			int jj=fg(j);
			if(k&1){
				if(s[jj]=='W') ss[jj]='B';
				else ss[jj]='W';
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%c",ss[i]);
	return 0;
}
        