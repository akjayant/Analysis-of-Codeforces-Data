#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
char s[N],t[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		scanf("%s%s",&s,&t);
		vector<int>g;
		for(int i=0;i<n;i++) if(s[i]!=t[i]) g.push_back(i);
		if(g.size()!=2){puts("No");continue;}
		int a=g[0],b=g[1];
		if((s[a]==s[b])&&(t[b]==t[a])) puts("Yes");
		else puts("No");
	}
	
	return 0;
}