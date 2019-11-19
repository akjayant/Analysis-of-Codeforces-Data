#include <bits/stdc++.h>
using namespace std;
#define M 1005
char S[M];
int n;
void tomax(int &x,int y){
	if(x<y)x=y;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d%s",&n,S+1);
		int ans=n;
		for(int i=1;i<=n;i++)
			if(S[i]=='1')tomax(ans,i<<1),tomax(ans,n-i+1<<1);
		for(int i=1;i<=n;i++)if(S[i]=='1')
			for(int j=i+1;j<=n;j++)if(S[j]=='1')
				tomax(ans,(i-j+1)*2+max(n-j,i-1));
		cout<<ans<<endl;
	}
	return 0;
}