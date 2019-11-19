#include <bits/stdc++.h>
using namespace std;
int T,n;
char s[1010];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		scanf("%s",s+1);
		int ans=n;
		for(int i=1;i<=n;i++){
			if(s[i]=='1') ans=max(ans,max(n+1,max(2*i,2*(n-i+1))));
		}
		cout<<ans<<endl;
	}
}