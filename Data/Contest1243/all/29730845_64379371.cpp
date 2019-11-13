#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
const int mx=2e5+10;

char s1[mx],s2[mx];
int s[mx];
int t,n;

int main(){
	scanf("%d",&t);
	while(t--){
		int ans=0;
		scanf("%d",&n);
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		for(int i=1;i<=n;i++)
		{
			if(s1[i]!=s2[i])
			{
			  s[++ans]=s1[i]-'a';
			  s[++ans]=s2[i]-'a';
		    }
		}
		if(ans==2||ans>4)
		printf("No\n");
		else if(ans==0)
		printf("Yes\n");
		else{
			if(s[1]==s[3]&&s[2]==s[4])
			printf("Yes\n");
			else
			printf("No\n");
		}
	}
	return 0;
}
			