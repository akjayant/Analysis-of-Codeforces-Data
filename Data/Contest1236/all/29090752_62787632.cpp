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

int power(int x, int y, int p)
{
	int res=1;
	x=x%p;
	while(y>=1)
	{
		if(y%2) res = (res*x)%p;
		x = ((x%p)*(x%p))%p;
		y/=2; 
	}

	return res;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	cout<<power(power(2,m,M)-1, n, M)<<endl;
}

signed main()
{
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int t;
		t=1;
		while(t--)
		{
			solve();
		}
}	