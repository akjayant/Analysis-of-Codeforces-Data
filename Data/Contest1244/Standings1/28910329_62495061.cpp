#include<bits/stdc++.h>
#define N 400010
using namespace std;
char s[N],ans[N];
int GG[N],cnt;
bool vis[N];
int L[N],R[N];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);

	int num=0;
	for(int i=1;i<=n;i++)if(s[i]=='B')num++;
	if(num==0||num==n)return 0*printf("%s\n",s+1);

	int num2=0;
	for(int i=2;i<=n;i++)if(s[i]!=s[i-1])num2++;
	if(s[1]!=s[n])num2++;
	if(num2==n){
		if(k&1)for(int i=1;i<=n;i++)s[i]=(s[i]=='B'?'W':'B');
		return 0*printf("%s\n",s+1);
	}

	for(int i=n+1;i<=2*n;i++)s[i]=s[i-n];
	for(int i=1;i<2*n;i++){
		if(!vis[i]&&s[i]==s[i+1]){
			vis[i]=1,GG[i]=(s[i]=='B'?1:2);
			while(i<2*n&&s[i+1]==s[i])i++,vis[i]=1,GG[i]=(s[i]=='B'?1:2);
		}
	}
	// for(int i=1;i<=2*n;i++)cout<<GG[i]<<" ";cout<<endl;
	int H=0;
	for(int i=1;i<=2*n;i++){
		if(GG[i])H=i;
		L[i]=H;
	}
	H=2*n+1;
	for(int i=2*n;i>=1;i--){
		if(GG[i])H=i;
		R[i]=H;
	}
	for(int i=1;i<=n;i++){
		if(GG[i])ans[i]=(GG[i]==1?'B':'W');
		else {
			int len1=(i+n)-L[i+n];
			int len2=R[i]-i;
			if(len1<len2){
				if(k>=len1)ans[i]=(GG[L[i+n]]==1?'B':'W');
				else {
					if(k&1)ans[i]=(s[i]=='B'?'W':'B');
					else ans[i]=s[i];
				}
			}
			else {
				if(k>=len2)ans[i]=(GG[R[i]]==1?'B':'W');
				else {
					if(k&1)ans[i]=(s[i]=='B'?'W':'B');
					else ans[i]=s[i];
				}
			}
		}
	}
	printf("%s\n",ans+1);
	return 0;
}