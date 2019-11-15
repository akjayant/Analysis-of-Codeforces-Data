#include<bits/stdc++.h>
using namespace std;

int T,n,a,b,c,ans[110],res;
char str[110];

int main(){
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);res=0;memset(ans,0,sizeof(ans));
		cin>>a>>b>>c;//石头，布，剪刀 
		scanf("%s",str+1);
		for(int i=1;i<=n;i++){
			if(str[i]=='R'&&b)b--,ans[i]=2,res++;
			if(str[i]=='P'&&c)c--,ans[i]=3,res++;
			if(str[i]=='S'&&a)a--,ans[i]=1,res++;
		}
		if(res>=(n+1>>1)){
			printf("YES\n");
			for(int i=1;i<=n;i++)
			{
				if(ans[i]==1)printf("R");
				if(ans[i]==2)printf("P");
				if(ans[i]==3)printf("S");
				if(ans[i]==0){
					if(a)printf("R"),a--;
					else if(b)printf("P"),b--;
					else if(c)printf("S"),c--;
				}
			}printf("\n");
		}
		else printf("NO\n");
	}return 0;
	
	
}