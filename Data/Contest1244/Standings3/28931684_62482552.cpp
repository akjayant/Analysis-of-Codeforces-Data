#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int T,flg;
ll n,p,d,w,k,x,y,z;
bool func(ll n,ll p,ll w,ll d){
	x=p/w;
	k=p%w;
	if(x>n||(x==n&&k)||(w==d&&k))
		return 0;
	if(!k){
		z=n-x;
		return 1;
	}
		
	for(int i=1;i<w;i++){
		if(i*d%w==k){
			y=i;
			flg=1;
			break;
		}
	}
	if(!flg||y*d>p)
		return 0;
	x=(p-y*d)/w;
	if(x+y>n)
		return 0;
	z=n-x-y;
		return 1;
}
int main(){
	ios::sync_with_stdio(false);
	//scanf("%d",&T);
	cin>>n>>p>>w>>d;
	if(!func(n,p,w,d))
		cout<<-1;
	else
		cout<<x<<' '<<y<<' '<<z;
	return 0;
}
