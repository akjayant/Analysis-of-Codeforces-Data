#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005][4];
ll c[100005];
ll vis[100005];
vector<int>v[100005];
ll tmp=0;
void work(int past,int i,int x,int y)
{
	for(int j=0;j<v[i].size();j++){
		if(v[i][j]==past){
			continue;
		}else{
			tmp+=a[v[i][j]][x^y];
			work(i,v[i][j],y,x^y);
		}
	}
}
void work1(int past,int i,int a,int b)
{
	for(int j=0;j<v[i].size();j++){
		if(v[i][j]==past){
			continue;
		}else{
			c[v[i][j]]=a^b;
			work1(i,v[i][j],b,a^b);
		}
	}
}
int main()
{
     int n;
     scanf("%d",&n);
     for(int i=1;i<=3;i++){
     	for(int j=1;j<=n;j++){
     		scanf("%lld",&a[j][i]);
     	}
     }
     for(int i=1;i<n;i++){
     	int x,y;
     	scanf("%d%d",&x,&y);
     	vis[x]++;
     	vis[y]++;
     	v[x].push_back(y);
     	v[y].push_back(x);
     }
     int st;
     for(int i=1;i<=n;i++){
     	if(vis[i]>2){
     		printf("-1\n");
     		return 0;
     	}
     	if(vis[i]==1){
     		st=i;
     	}
     }
     ll ans=1e18;
     tmp=a[st][2];
     int k=0;
     work(-1,st,1,2);
     if(tmp<ans){
     	ans=tmp;
     	k=1;
     }
     tmp=a[st][3];
     work(-1,st,1,3);
     if(tmp<ans){
     	ans=tmp;
     	k=2;
     }
     tmp=a[st][1];
     work(-1,st,2,1);
    if(tmp<ans){
     	ans=tmp;
     	k=3;
    }
     tmp=a[st][3];
     work(-1,st,2,3);
    if(tmp<ans){
     	ans=tmp;
     	k=4;
    }
     tmp=a[st][1];
     work(-1,st,3,1);
    if(tmp<ans){
     	ans=tmp;
     	k=5;
    }
     tmp=a[st][2];
     work(-1,st,3,2);
    if(tmp<ans){
     	ans=tmp;
     	k=6;
    }
    printf("%lld\n",ans);
    if(k==1){
    	c[st]=2;
    	work1(-1,st,1,2);
    }else if(k==2){
    	c[st]=3;
    	work1(-1,st,1,3);
    }else if(k==3){
    	c[st]=1;
    	work1(-1,st,2,1);
    }else if(k==4){
    	c[st]=3;
    	work1(-1,st,2,3);
    }else if(k==5){
    	c[st]=1;
    	work1(-1,st,3,1);
    }else if(k==6){
    	c[st]=2;
    	work1(-1,st,3,2);
    }
    for(int i=1;i<n;i++){
    	printf("%lld ",c[i]);
    }
    printf("%lld\n",c[n]);
}