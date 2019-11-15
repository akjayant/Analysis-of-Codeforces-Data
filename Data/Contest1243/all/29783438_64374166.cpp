#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define mm 1000000007
#define ll long long
int n,m,t,a,b,c,an,ans,aa[200005],bb[200005],gg;
char s[200005],ss[200005],g;
priority_queue<int> q;
int main(){
	scanf("%d",&t);
	for (int ii=0;ii<t;ii++){
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&aa[i]);
		ans = 0;
		sort(aa,aa+n);
		for (int i=n;i>=1;i--){
			a = 0;
			for (int j=0;j<n;j++){
				if (aa[j]>=i) a++;
				else a = 0;
				if (a>=i && !ans) ans = i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}