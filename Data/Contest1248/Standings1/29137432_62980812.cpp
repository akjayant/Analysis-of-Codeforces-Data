/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL t,n,x,a,b;
vector <LL> v,vv;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	rep(tn,t)
	{
		v.clear();
		vv.clear();
		cin>>n;
		rep(i,n)
		{
			cin>>x;
			v.pb(x);
		}
		cin>>n;
		rep(i,n)
		{
			cin>>x;
			vv.pb(x);
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		sort(vv.begin(),vv.end());
		vv.erase(unique(vv.begin(),vv.end()),vv.end());
		a=b=0;
		rep(i,v.size()) if(v[i]%2==0) a++;
		rep(i,vv.size()) if(vv[i]%2==0) b++;
		cout<<a*b+(v.size()-a)*(vv.size()-b)<<endl;
	}
	return 0;
}