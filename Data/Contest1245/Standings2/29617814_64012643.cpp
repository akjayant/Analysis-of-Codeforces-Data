#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define mm 1000000007
#define ll long long
ll n,m,t,ans,an,ann,a,b,c,aa[200005],bb[200005],dd[200005],gp[20005],ed;
priority_queue<int > q;
char s[200005],ss[205];
struct yo{
	ll x,y,k,c;
}cc[2005];
struct pp{
	ll x,y,k;
	bool operator < (const pp & tt) const{
		return k<tt.k;
	}
}ee[4000005];
int find(int x){
	return gp[x]==x?x:gp[x]=find(gp[x]);
}
void added(ll a,ll b,ll c){
	ee[ed].x = a;
	ee[ed].y = b;
	ee[ed].k = c;
	ed ++;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&cc[i].x,&cc[i].y);
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&cc[i].c);
	}	
	for (int i=1;i<=n;i++){
		scanf("%d",&cc[i].k);
	}		
	for (int i=1;i<=n;i++) gp[i] = i;
	for (int i=1;i<=n;i++){
		added(0,i,cc[i].c);
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			added(i,j,(cc[i].k+cc[j].k)*(abs(cc[i].x-cc[j].x)+abs(cc[i].y-cc[j].y)));
		}
	}
	sort(ee,ee+ed);
	for (int i=0;i<ed;i++){
		a = ee[i].x;
		b = ee[i].y;
		c = ee[i].k;
		if (find(gp[a])!=find(gp[b])){
			if (a==0){
				aa[an] = b;
				an ++;
			}else{
				bb[ann] = a;
				dd[ann] = b;
				ann ++;
			}
			ans += c;
			gp[find(gp[a])]=find(gp[b]);
		}
	}
	printf("%I64d\n%I64d\n",ans,an);
	for (int i=0;i<an;i++) printf(i==an-1?"%I64d\n":"%I64d ",aa[i]);
	printf("%I64d\n",ann);
	for (int i=0;i<ann;i++) printf("%I64d %I64d\n",bb[i],dd[i]);		
	return 0;
}