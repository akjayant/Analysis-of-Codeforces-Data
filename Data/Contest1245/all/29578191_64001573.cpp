#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
typedef pair<int,int>pa;
priority_queue<pa,vector<pa>, greater<pa> >q;

int n;
const int N=110;
char ch[N];
int cnt[3],b[3];
int a[N];
int ans[N];
char buf[]="RPS";
int main(){
#ifdef WK
	freopen("in.txt","r",stdin);
#endif
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans[n]=0;
		for(int i=0;i<3;i++)scanf("%d",&cnt[i]),b[i]=cnt[i];
		scanf("%s",ch);
		for(int i=0;i<n;i++){
			if(ch[i]=='R')a[i]=0;
			else if(ch[i]=='P')a[i]=1;
			else a[i]=2;
		}
		int sum=0;
		for(int i=0;i<n;i++){
			int t=(a[i]+1)%3;
			if(cnt[t]){
				cnt[t]--;
				ans[i+1]=t;
				sum++;
			}else ans[i+1]=-1;
		}
		if(sum<(n+1)/2){
			printf("NO\n");
			continue;
		}
		
		printf("YES\n");
		for(int i=1;i<=n;i++){
			if(ans[i]==-1){
				for(int j=0;j<3;j++){
					if(cnt[j]){
						ans[i]=j;cnt[j]--;break;
					}
				}
			}
			
			printf("%c",buf[ans[i]]);
		}
		printf("\n");
	} 

	return 0; 
} 