#include<bits/stdc++.h>
using namespace std;
char s[110];
int main(){
	int T,n;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",&s);
		int a_=0,b_=0,c_=0;
		for(int i=0;s[i];i++){
			if(s[i]=='R') a_++;
			else if(s[i]=='P') b_++;
			else c_++;
		}
		int ans=0;
		ans+=min(a,c_);
		ans+=min(b,a_);
		ans+=min(c,b_);
		int tmp=(n&1)? n/2+1:n/2;
		if(ans<tmp) puts("NO");
		else{
			puts("YES");
			string t="";
			for(int i=0;i<n;i++){
				if(s[i]=='R'&&b) {
					t+='P';b--;
				}
				else if(s[i]=='S'&&a) {
					t+='R';a--;
				}
				else if(s[i]=='P'&&c){
					t+='S';c--;
				}
				else t+=' ';
			}	
			for(int i=0;i<n;i++){
				if(t[i]!=' ') continue;
				if(a) t[i]='R',a--;
				else if(b) t[i]='P',b--;
				else t[i]='S',c--;
			}
			cout<<t<<endl;
		}		
	} 
	return 0;
}