#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long LL;
const int mxn=100010;
set<int> sa[mxn],sb[mxn],sc,sd;
int n,m,k;
LL ans;
void solve(int x,int y,int d){
	if (d==1){
		set<int>::iterator sx=sa[x].upper_bound(y),sy=sc.upper_bound(y);
		int z;
		if (sx==sa[x].end()) z=(*sy)-1;
		else z=min(*sx,*sy)-1;
		if (z==y) return;
		else ans+=z-y,sd.insert(x),solve(x,z,2);
	}
	else if (d==2){
		set<int>::iterator sx=sb[y].upper_bound(x),sy=sd.upper_bound(x);
		int z;
		if (sx==sb[y].end()) z=(*sy)-1;
		else z=min(*sx,*sy)-1;
		if (z==x) return;
		else ans+=z-x,sc.insert(y),solve(z,y,3);
	}
	else if (d==3){
		set<int>::iterator sx=sa[x].lower_bound(y),sy=sc.lower_bound(y);
		sy--;
		int z;
		if (sx==sa[x].begin()) z=(*sy)+1;
		else sx--,z=max(*sx,*sy)+1;
		if (z==y) return;
		else ans+=y-z,sd.insert(x),solve(x,z,4);
	}
	else if (d==4){
		set<int>::iterator sx=sb[y].lower_bound(x),sy=sd.lower_bound(x);
		sy--;
		int z;
		if (sx==sb[y].begin()) z=(*sy)+1;
		else sx--,z=max(*sx,*sy)+1;
		if (z==x) return;
		else ans+=x-z,sc.insert(y),solve(z,y,1);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1,x,y;i<=k;++i){
		scanf("%d%d",&x,&y);
		sa[x].insert(y);
		sb[y].insert(x);
	}
	ans=1;
	sc.insert(0);
	sc.insert(m+1);
	sd.insert(0);
	sd.insert(n+1);
	solve(1,1,1);
	if (ans+k==1ll*n*m) return puts("Yes"),0;
	sc.clear();
	sd.clear();
	ans=1;
	sc.insert(0);
	sc.insert(m+1);
	sd.insert(0);
	sd.insert(n+1);
	solve(1,1,2);
	if (ans+k==1ll*n*m) return puts("Yes"),0;
	puts("No");
	return 0;
}