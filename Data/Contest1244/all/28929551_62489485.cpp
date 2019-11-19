#include<bits/stdc++.h>
using namespace std;
int n,u,v,d[100005],cnt[100005];
int c[4][100005],go[100005][2],vis[100005];
int li,lj,lo,lie[100005],an[100005];
long long add,ans=1e18;

int main(){
	scanf("%d",&n);
	for(int j=1;j<=3;j++){
		for(int i=1;i<=n;i++) scanf("%d",&c[j][i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		go[u][d[u]]=v,go[v][d[v]]=u;
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++) cnt[d[i]]++;
	if(cnt[1]==2&&cnt[2]==n-2){
		int pre;
		for(int i=1;i<=n;i++){
			if(d[i]==1){
				pre=i;
				break;
			}
		} 
		vis[0]=vis[pre]=1;
		lie[1]=pre;
		for(int i=2;i<=n;i++){
			if(!vis[go[lie[i-1]][0]]) lie[i]=go[lie[i-1]][0];
			else lie[i]=go[lie[i-1]][1];
			vis[go[lie[i-1]][0]]=vis[go[lie[i-1]][1]]=1;
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(i!=j){
					int o;add=0;
					if((i==1&&j==2)||(i==2&&j==1)) o=3;
					if((i==1&&j==3)||(i==3&&j==1)) o=2;
					if((i==2&&j==3)||(i==3&&j==2)) o=1;
					for(int k=1;k<=n;k++){
						if(k%3==1) add+=c[i][lie[k]];
						else if(k%3==2) add+=c[j][lie[k]];
						else add+=c[o][lie[k]];
					}
					if(ans>add){
						ans=add;
						li=i,lj=j,lo=o;
					}
				}
			}
		}
		cout<<ans<<endl;
		for(int k=1;k<=n;k++){
			if(k%3==1) an[lie[k]]=li;
			else if(k%3==2) an[lie[k]]=lj;
			else an[lie[k]]=lo;
		}
		for(int k=1;k<=n;k++) printf("%d ",an[k]);
	}
	else puts("-1\n");

	return 0;
}