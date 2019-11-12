/*
Author Shivam
*/
#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define m_p			make_pair
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i =a, i>=b;i--)
#define sz(x)       (int)x.size()
#define F			first
#define S			second
#define debug(x)	for(int i=0;i<x;i++) cout<<"##########"<<endl
#define M			1000000007 
#define int			long long int
#define lMax		LLONG_MAX
#define pii 		pair<int ,int >
#define	all(a)		a.begin(), a.end()
#define vi 			vector<int> 
#define vii 		vector<pii> 
#define ve          vector
#define endl		"\n"
#define double 		long double
#define couts		cout<<setprecision(12)<<fixed					
// queue<int> , prefix_sum(a,a+n) , reverse(a,a+n) , priority_queue <int> max heap , priority_queue <int, vector<int>, greater<int> > min heap;
// == > != precedence gretaer then & , << precedence greater than <= == => , 
//int chk, cnt, fl, pos, in, src, tar, val, res. dummy;  fill (myvector.begin(),myvector.begin()+4,5), freq;					
// can


void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	int ans=0;
	rep(j,0,b+1)
	{

			if(2*j<=c)
			{
				int tmp=j+2*j;
				tmp+=3*min((b-j)/2,a);
				ans=max(ans, tmp);
			}
	}

	cout<<ans<<endl;
}

signed main()
{
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int t;
		cin>>t;
		while(t--)
		{
			solve();
		}
}	