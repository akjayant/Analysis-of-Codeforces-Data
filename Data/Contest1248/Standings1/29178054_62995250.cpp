// Running Offline
// g++ tester.cpp
// ./a.out
// #include "/Users/manasgupta/Desktop/stdc++.h"
 
#pragma compile "03"
#include<bits/stdc++.h>
using namespace std;
// #define int long long int 
#define float double
#define pi pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define inf 1e9
#define EPS 1e-6
#define endl '\n'
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO(name1, name2) \
    freopen(name1".txt","r",stdin); \
    freopen(name2".txt","w",stdout);
 
const int N=100005;
const int mod = 1000000007;
 
int gcd(int a, int b)
{
	if (b==0) return a;
	return gcd(b, a%b);
}
 
int n;
string s;
int ans;
pair<int, int> ind;

signed main()
{
	IOS;
	cin>>n;
	cin>>s;
	ans=0;
	ind.fi=1;
	ind.se=1;
	int gg=0;
	for (int i=0; i<n; i++)
	{
		if (s[i]=='(') gg++;
	}
	if (n%2==1 or gg!=n/2)
	{
		cout<<ans<<endl;
		cout<<ind.fi<<" "<<ind.se<<endl;
		return 0;
	}
	for (int i=0; i<n; i++)
	{
		for (int j=i; j<n; j++)
		{
			string temp;
			temp=s;
			char wow;
			wow=s[j];
			temp[j]=temp[i];
			temp[i]=wow;
			int damn=0;
			int flag=1;
			int t=0;
			int lol=0;
			for (int i=0; i<n; i++)
			{
				if (temp[i]=='(')
				{
					t++;
				}
				else
				{
					t--;
				}
				lol=min(lol, t);
			}
			for (int i=0; i<n; i++)
			{
				if (temp[i]=='(')
				{
					t++;
				}
				else
				{
					t--;
				}
				if (t==lol)
				{
					damn++;
				}
			}
			// cout<<(i+1)<<" "<<(j+1)<<" "<<s<<" "<<damn<<" "<<lol<<endl;
			if (flag and ans<damn)
			{
				ans=damn;
				ind.fi=i+1;
				ind.se=j+1;
			}
		}
	}
	cout<<ans<<endl;
	cout<<ind.fi<<" "<<ind.se<<endl;
	return 0;
}