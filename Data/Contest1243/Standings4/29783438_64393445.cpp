#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define mm 1000000007
#define ll long long
int n,m,t,a,b,c,an,ans,aa[200005],bb[4005][2],gg,cc[30];
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
		memset(cc,NULL,sizeof(cc));
		memset(bb,NULL,sizeof(bb));		
		for (int i=0;i<n;i++) cc[s[i]-'a']++;
		for (int i=0;i<n;i++) cc[ss[i]-'a']++;
		for (int i=0;i<26;i++) if (cc[i]%2!=0) a = 1;
		if (a){
			printf("No\n");
			continue;
		}		
		for (int i=1;i<=2*n;i++){
			for (int j=0;j<n;j++){
				if (s[j]!=ss[j]){
					a = 0;
					for (int k=j+1;k<n;k++) if (s[k] == s[j] && !a){
						bb[ans][0] = k+1;
						bb[ans][1] = j+1;
						ans ++;
						g = s[k];
						s[k] = ss[j];
						ss[j] = g;
						a++;
					}
					if (!a){
						for (int k=j+1;k<n;k++) if (ss[k] == s[j]&& !a){
							bb[ans][0] = k+1;
							bb[ans][1] = k+1;
							ans ++;
							bb[ans][0] = k+1;
							bb[ans][1] = j+1;
							ans ++;							
							g = ss[j];
							ss[j] = ss[k];
							ss[k] = s[k];
							s[k] = g;
							a++;
						}						
					}
				}
			}
			
		}
		printf("Yes\n%d\n",ans);
		for (int i=0;i<ans;i++) printf("%d %d\n",bb[i][0],bb[i][1]);
	}
	return 0;
}