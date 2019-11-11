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

int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int w[3];
		cin>>w[0]>>w[1]>>w[2];
		string s;
		cin>>s;
		int ar[n];
		for(int i=0;i<n;i++)
		{
			if(s[i]=='R')
			{
				ar[i]=0;
			}
			else if(s[i]=='P')
			{
				ar[i]=1;
			}
			else
			{
				ar[i]=2;
			}			
		}
		int least=(n+1)/2;
		int ans[n];
		for(int i=0;i<n;i++)
		{
			ans[i]=-1;
		}
		int win=0;
		for(int i=0;i<n;i++)
		{
			int ind=(ar[i]+1)%3;
			if(w[ind]>0)
			{
				ans[i]=ind;
				w[ind]--;
				win++;
			}
		}
		if(win<least)
		{
			cout<<"NO\n";continue;
		}
		for(int i=0;i<n;i++)
		{
			if(ans[i]==-1)
			{
				for(int j=0;j<3;j++)
				{
					if(w[j])
					{
						ans[i]=j;
						w[j]--;
						break;
					}
				}
			}
		}	
		cout<<"YES\n";	
		for(int i=0;i<n;i++)
		{
			if(ans[i]==0)
			{
				cout<<"R";
			}
			else if(ans[i]==1)
			{
				cout<<"P";
			}
			else
			{
				cout<<"S";
			}
		}
		cout<<endl;
	}
}
