#include<bits/stdc++.h>
typedef long long LL;
typedef double db;
#define REP(i,s,t) for(register int i=s;i<=t;++i)
#define PER(i,s,t) for(register int i=s;i>=t;--i)
#define FOREDGE(i,x,v) for(int i=fir[x],v=to[i];i;i=nex[i],v=to[i])
template<typename T>inline T in(){
    T ans=0;bool b=0;char ch=getchar();
    while(ch<'0'||ch>'9')b=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')ans=ans*10+ch-48,ch=getchar();
    return b?-ans:ans;
}
#define II in<int>()
#define IL in<LL>()
//<-----QAQ----->

char ch[105],res[105];
int ans;
int main(){
	int T=II;
	while(T--){
		int n=II,a=II,b=II,c=II;
		ans=0;
		scanf("%s",ch+1);
		std::memset(res,0,sizeof res);
		REP(i,1,n){
			switch(ch[i]){
				case 'R':if(b)b--,ans++,res[i]='P';break;
				case 'P':if(c)c--,ans++,res[i]='S';break;
				case 'S':if(a)a--,ans++,res[i]='R';break;
			}
		}
		REP(i,1,n){
			if(res[i]==0){
				if(a){
					res[i]='R';
					a--;
					continue;
				}
				if(b){
					res[i]='P';
					b--;
					continue;
				}
				if(c){
					res[i]='S';
					c--;
					continue;
				}
			}
		}
		puts(ans*2>=n?"Yes":"No");
		if(ans*2>=n)puts(res+1);
	}	
}