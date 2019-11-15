#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define mm 1000000007
#define ll long long
int n,m,t,a,b,c,an,ans,aa[200005],bb[200005],gg;
char s[20005],ss[20005],g;
priority_queue<int> q;
int main(){
	scanf("%d",&t);
	for (int ii=0;ii<t;ii++){
		scanf("%d\n",&n);
		memset(s,NULL,sizeof(s));
		gets(s);
		memset(ss,NULL,sizeof(ss));
		gets(ss);	
		a = 0;
		an = 0;
		ans = 0;
		for (int i=0;i<n;i++) if (s[i]!=ss[i]){
			a++;
			if (a == 1) an = i;
			else if (a == 2) ans = i;
		}
		if (a == 2){
			if (s[an] == s[ans] && ss[ans] == ss[an]) printf("Yes\n");
			else printf("No\n");
		}	else printf("No\n");
	}
	return 0;
}