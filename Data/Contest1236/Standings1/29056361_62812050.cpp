#include<bits/stdc++.h>

using namespace std;

#define DIM 300009
#define INF ((long long)1e18+9ll)
#define pairll pair<long long,long long>
#define fi first
#define se second
#define ld long double
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define amen exit(0)
#define endl '\n'
#define MODULO 1000000007

long long i,j,k,l,n,m,rx,lx,ry,ly;

set<long long>r[DIM],c[DIM];

long long findleft(long long x,long long num,char t){
	if(t=='r'){
		auto it=r[num].upper_bound(x);
		it--;
		return *it;
	}
	else{
		auto it=c[num].upper_bound(x);
		it--;
		return *it;
	}
}

long long findright(long long x,long long num,char t){
	if(t=='r'){
		auto it=r[num].upper_bound(x);
		return *it;
	}
	else{
		auto it=c[num].upper_bound(x);
		return *it;
	}
}

long long cnt=0;

int main(){
 
	fast; 

	cin>>n>>m>>k;

	for(i=1;i<=n;i++)r[i].insert(0),r[i].insert(m+1);
	for(i=1;i<=m;i++)c[i].insert(0),c[i].insert(n+1);

	lx=ly=0;
	rx=n+1;
	ry=m+1;

	cnt=n*m-k;

	long long xx,yy;

	for(i=1;i<=k;i++){
		cin>>xx>>yy;
		r[xx].insert(yy);
		c[yy].insert(xx);
	}

	k=findright(1,1,'c');
	if(k-1==cnt)return cout<<"Yes"<<endl,0;

	long long x=1,y=1,curr=1;

	cnt--;

	while(1){
		if(curr==1){
			k=min(ry,findright(y,x,'r'));
			cnt-=k-y-1;
			if(k==y+1)break;
			lx=x;
			y=k-1;
		}
		if(curr==2){
			k=min(rx,findright(x,y,'c'));
			cnt-=k-x-1;
			if(k==x+1)break;
			ry=y;
			x=k-1;
		}
		if(curr==3){
			k=max(ly,findleft(y,x,'r'));
			cnt-=y-k-1;
			if(k==y-1)break;
			y=k+1;
			rx=x;
		}
		if(curr==4){
			k=max(lx,findleft(x,y,'c'));
			cnt-=x-k-1;
			if(k==x-1)break;
			x=k+1;
			ly=y;
		}

		//cout<<"A"<<' '<<x<<' '<<y<<endl;
		curr++;
		if(curr>4)curr=1;
	}

	//cout<<cnt<<endl;

	if(cnt==0)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	amen;
}