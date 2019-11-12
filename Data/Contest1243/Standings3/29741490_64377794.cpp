#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+5;
int n;
char s[maxn],t[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);scanf("%s",t+1);
		vector<int>P;
		for(int i=1;i<=n;i++){
			if(s[i]!=t[i])P.push_back(i);
		}
		if((int)P.size()==0){
			puts("Yes");
			continue;
		}
		if((int)P.size()!=2){
			puts("No");
			continue;	
		}
		int p0=P[0],p1=P[1];
		if(s[p0]==s[p1] && t[p0]==t[p1])puts("Yes");
		else puts("No");
	}
    return 0;
}
