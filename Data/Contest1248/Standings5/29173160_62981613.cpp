		
#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long int
#define mem(x) memset(x,0,sizeof(x))
#define setbits(x)  __builtin_popcount(x)
#define ull unsigned long long int
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep1(i,a,b)  for(int i=a;i<=b;i++)
#define fun(s,e,c) for(int i=s;i<e;i+=c)
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
using namespace std;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef pair<ll,int> li;
inline void fast()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main()
{
	fast();
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,p,q;
		vector<int>v1,v2;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>p;
			v1.pb(p);
		}
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>q;
			v2.pb(q);
		}
		//sort(v1.begin(),v1.end());
		//sort(v2.begin(),v2.end());
		ll r1[2],r2[2];
		r1[0]=r1[1]=r2[0]=r2[1]=0;
		for(auto it:v1)
		{
			if(it%2)
				r1[1]+=1;
			else
				r1[0]+=1;
		}
		for(auto it:v2)
		{
			if(it%2)
				r2[1]+=1;
			else
				r2[0]+=1;
		}
		 ll ans=r1[1]*r2[1]+r1[0]*r2[0];
		 cout<<ans<<"\n";

	}

}