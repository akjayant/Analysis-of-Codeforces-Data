/*Author: ADITYA SHETH*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define endl "\n" 
#define int long long // remove when constraints are tight.
/*-------------------------------------------------------------------------------------------------------------------------------------*/
string s;
const int N=1e5+10;
int dp[N][2];
int n;

int rec(int ind,int prev)
{
	if(ind>=n)
	{
		return 1;
	}
	int &ans=dp[ind][prev];
	if(ans>=0)
	{
		return ans;
	}
	ans=0;
	if(ind==0)
	{
		ans=rec(ind+1,0);
		return ans;
	}
	if(prev)
	{
		ans=rec(ind+1,0);
		return ans;
	}

	if(s[ind]=='u' && s[ind-1]=='u')
	{
		ans+=rec(ind+1,1);
	}
	if(s[ind]=='n' && s[ind-1]=='n')
	{
		ans+=rec(ind+1,1);
	}
	ans+=rec(ind+1,0);
	ans%=MOD;
	return ans;
}
int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='m' || s[i]=='w')
		{
			cout<<0<<endl;
			return 0;
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0);
}
