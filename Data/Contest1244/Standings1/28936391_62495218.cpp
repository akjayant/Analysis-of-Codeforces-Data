#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define M 200005
char S[M];
int vis[M],F[M];
struct Node{
	int x,dr;
}Q[2][M<<3];
int Col(char c){
	return c=='W';
}
int mark[M],Ti;
int main(){
	int n,K;
	cin>>n>>K;
	int a=-1,b=n,len=0;
	scanf("%s",S);
	if(S[0]==S[n-1]){
		vis[0]=vis[n-1]=1;
		F[0]=F[n-1]=Col(S[0]);
		while(a+1<n&&S[a+1]==S[0])a++,vis[a]=1,F[a]=Col(S[0]);
		while(b-1>=0&&S[b-1]==S[n-1])b--,vis[b]=1,F[b]=Col(S[0]);
		if(a>=b)return printf("%s\n",S),0;
		Q[0][++len]=(Node){a,1};
		Q[0][++len]=(Node){b,-1};
	}
	for(int i=a+1;i<b;i++){
		int j=i;
		while(j+1<b&&S[j+1]==S[i])j++;
		if(i!=j){
			for(int k=i;k<=j;k++)vis[k]=1,F[k]=Col(S[i]);
			Q[0][++len]=(Node){i,-1};
			Q[0][++len]=(Node){j,1};
		}
		i=j;
	}
	int cur=0,hv=0;
//		for(int i=1;i<=len;i++)
//			cout<<Q[cur][i].x<<' '<<Q[cur][i].dr<<endl;
//		cout<<endl;
	while(K&&len){
		int Len=0;Ti++;
		for(int i=1;i<=len;i++){
			int x=(Q[cur][i].x+Q[cur][i].dr+n)%n;
			if(vis[x]){
				if(mark[x]==Ti){
					if(F[x]==F[Q[cur][i].x])continue;
					int be=Col(S[x])^hv;
					if(be==F[x])F[x]=x;
					else F[x]=F[Q[cur][i].x];
				}else continue;
			}
//			cout<<x<<endl;
			vis[x]=1,mark[x]=Ti;
			F[x]=F[Q[cur][i].x];
			Q[!cur][++Len]=(Node){x,Q[cur][i].dr};
		}
		hv^=1;
		len=Len;
		cur^=1;
//		break;
		K--;
	}
	for(int i=0;i<n;i++)
		if(vis[i]){
			if(F[i]==1)printf("W");
			else printf("B");
		}else {
			int col=Col(S[i])^hv;
			if(col==1)printf("W");
			else printf("B");
		}
	puts("");
	return 0;
}