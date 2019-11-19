#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define F first
#define S second
#define I insert
#define mp make_pair
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define debug1(a) cout<<" "<<#a<<" : "<<a<<"\n"
#define debug2(a,b) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<"\n"
#define debug3(a,b,c) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<"\n"
#define debug4(a,b,c,d) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<"\n"
#define INF (int)10000000000000000
#define PI (double)3.14159265358979
// #define M 421412341324321
#define MOD 1000000007


void func(string t, int &ans)
{
	int n = sz(t);
	int a = 0;
	int mn = INF;
	rep(i,n)
	{
		if (t[i]=='(')
		{
			a++;
		}
		else
		{
			a--;
		}
		mn = min(a,mn);
	}
	if (a!=0) return;
	if (mn>=0) ans++;
	// if (t=="()()()(())")
	// {
	// 	debug1(mn);
	// }
	int x =0 ;
	REP(i,1,n-1)
	{
		if (t[i-1]==')') x++;
		else x--;
		if (mn+x>=0) ans++;
		mn+=x;
		x=0;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin>>n;
	string s;
	cin>>s;
	map <int, pair<int, int>> m;
	rep(i,n)
	{
		REP(j,0,n-1)
		{
			string t = s;
			swap(t[i], t[j]);
			int ans = 0;
			func(t, ans);
			m[ans] = {i,j};
		}
	}
	// debug1(sz(m));
	if (m.size()==0)
	{
		cout<<"0\n";
		cout<<"1 2";
		return 0;
	}
	auto j = *(m.rbegin());
	cout<<j.F<<"\n";
	cout<<j.S.F+1<<" "<<j.S.S+1;



	return 0;
}