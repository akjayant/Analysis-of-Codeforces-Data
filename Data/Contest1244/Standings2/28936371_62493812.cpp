#include<bits/stdc++.h>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	int x=0,p=1;char c=getchar();
	while (c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while (c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const int N=1e5+5;
int c[N];
vector<int>id;
int n,a[N];
deque<pii >dq;
ll k;
//
int main(){
	n=getint();cin>>k;
	rep(i,n)a[i]=getint();
	rep(i,n)id.push_back(a[i]);
	sort(id.begin(),id.end());
	id.resize(unique(id.begin(),id.end())-id.begin());
	rep(i,n)c[lower_bound(id.begin(),id.end(),a[i])-id.begin()]++;
	rep(i,id.size())dq.push_back(mp(id[i],c[i]));
	while(dq.size()>1&&k){
	//	cout<<k<<endl;
		int mn=min(dq[0].second,dq.back().second);
		if(k<mn)break;
		if(dq[0].second==mn){
			
			ll x=min(k/dq[0].second,1ll*dq[1].first-dq[0].first);
		//	cout<<2<<endl;
			dq[0].first+=x;k-=1ll*x*dq[0].second;
			if(dq[0].first==dq[1].first)dq[1].second+=dq[0].second,dq.pop_front();
		//	cout<<x<<endl;
		}
		else{
			ll x=min(k/dq[dq.size()-1].second,1ll*dq[dq.size()-1].first-dq[dq.size()-2].first);
			dq[dq.size()-1].first-=x;k-=1ll*x*dq[dq.size()-1].second;
			if(dq[dq.size()-1].first==dq[dq.size()-2].first)dq[dq.size()-2].second+=dq[dq.size()-1].second,dq.pop_back();
		}
	}
	printf("%d\n",dq.back().first-dq[0].first);
	return 0;
}
