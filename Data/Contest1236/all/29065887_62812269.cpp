#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MAXN 100010
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const LL INF=0x3f3f3f3f3f3f3f3f;
vector<int> rv[MAXN],cv[MAXN];
set<int> rs,cs;
map<pair<int,int>,bool>mp;
int n,m,k;

void read(int &X){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	X=x*f;
}

int main(){
	read(n);read(m);read(k);
	rs.insert(0);rs.insert(m+1);
	cs.insert(0);cs.insert(n+1);
	for(int i=1;i<=n;i++) rv[i].push_back(0),rv[i].push_back(m+1);
	for(int i=1;i<=m;i++) cv[i].push_back(0),cv[i].push_back(n+1);
	for(int i=1,r,c;i<=k;i++){
		read(r);read(c);
		rv[r].push_back(c);
		cv[c].push_back(r);
	}
	for(int i=1;i<=n;i++) sort(rv[i].begin(),rv[i].end());
	for(int i=1;i<=m;i++) sort(cv[i].begin(),cv[i].end());
	int x=1,y=1,dir=1,x1,y1;
	LL vis=1;
	while(1){
		if(dir==1){
			x1=x;
			y1=*upper_bound(rv[x].begin(),rv[x].end(),y);
			y1=min(y1,*rs.upper_bound(y));
			cs.insert(x);
			y1--;
			vis+=y1-y;
			dir=2;
		}
		else if(dir==2){
			y1=y;
			x1=*upper_bound(cv[y].begin(),cv[y].end(),x);
			x1=min(x1,*cs.upper_bound(x));
			rs.insert(y);
			x1--;
			vis+=x1-x;
			dir=3;
		}
		else if(dir==3){
			x1=x;
			y1=*(lower_bound(rv[x].begin(),rv[x].end(),y)-1);
			set<int>::iterator pos=rs.lower_bound(y);pos--;
			y1=max(y1,*pos);
			cs.insert(x);
			y1++;
			vis+=y-y1;
			dir=4;
		}
		else if(dir==4){
			y1=y;
			x1=*(lower_bound(cv[y].begin(),cv[y].end(),x)-1);
			set<int>::iterator pos=cs.lower_bound(x);pos--;
			x1=max(x1,*pos);
			rs.insert(y);
			x1++;
			vis+=x-x1;
			dir=1;
		}
		x=x1;y=y1;
		if(mp[make_pair(x,y)]==1) break;
		mp[make_pair(x,y)]=1;
	}
	if(vis<1ll*n*m-k) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}